#include <windows.h> // Windows API 관련 함수들을 위해
#include <pdh.h>     // Performance Data Helper (PDH) 함수들을 위해
#include <pdhmsg.h>  // PDH 에러 메시지들을 위해
#include <stdio.h>   // 파일 입출력 및 표준 입출력을 위해
#include <time.h>    // 시간 관련 함수들을 위해

#pragma comment(lib, "pdh.lib") // pdh.lib 라이브러리를 링크합니다.

#define LOG_FILENAME "cpu_usage_log.txt"
#define INTERVAL_SECONDS 5 // 5초마다 측정

int main() {
    PDH_STATUS status;
    HQUERY hQuery;       // PDH 쿼리 핸들
    HCOUNTER hCounter;   // PDH 카운터 핸들
    FILE* logFile;       // 로그 파일 포인터
    char timestamp[30];  // 시간을 저장할 버퍼
    time_t rawTime;
    struct tm* timeInfo;

    // 1. 로그 파일 열기 (없으면 생성, 있으면 이어쓰기)
    logFile = fopen(LOG_FILENAME, "a"); // "a"는 append 모드 (이어쓰기)
    if (logFile == NULL) {
        printf("에러: 로그 파일을 열 수 없습니다: %s\n", LOG_FILENAME);
        return 1;
    }

    // 파일이 비어있다면 헤더를 추가 (최초 실행 시)
    fseek(logFile, 0, SEEK_END);
    if (ftell(logFile) == 0) {
        fprintf(logFile, "===== CPU 사용량 로그 (%d초 간격) =====\n", INTERVAL_SECONDS);
        fprintf(logFile, "시간, %% Processor Time\n");
    }
    fflush(logFile); // 버퍼를 비워 파일에 즉시 쓰도록 합니다.

    printf("CPU 사용량 로깅을 시작합니다. 로그는 [%s] 에 기록됩니다.\n", LOG_FILENAME);
    printf("중지하려면 Ctrl+C를 누르세요.\n");

    // 2. PDH 쿼리 열기
    // PdhOpenQuery는 새로운 쿼리 핸들을 생성합니다. 이 핸들을 통해 성능 카운터를 추가하고 데이터를 수집할 수 있습니다.
    status = PdhOpenQuery(NULL, 0, &hQuery);
    if (status != ERROR_SUCCESS) {
        printf("에러: PdhOpenQuery 실패 (오류 코드: 0x%lx)\n", status);
        fclose(logFile);
        return 1;
    }

    // 3. "% Processor Time" 카운터 추가
    // PdhAddCounter는 특정 성능 카운터에 대한 핸들을 쿼리에 추가합니다.
    // "\Processor(_Total)\% Processor Time"은 시스템 전체 CPU 사용률을 나타내는 카운터 경로입니다.
    status = PdhAddCounter(hQuery, "\\Processor(_Total)\\% Processor Time", 0, &hCounter);
    if (status != ERROR_SUCCESS) {
        printf("에러: PdhAddCounter 실패 (오류 코드: 0x%lx)\n", status);
        PdhCloseQuery(hQuery);
        fclose(logFile);
        return 1;
    }

    // 4. 첫 번째 데이터 샘플 수집 (나중에 차이값을 계산하기 위함)
    status = PdhCollectQueryData(hQuery);
    if (status != ERROR_SUCCESS) {
        printf("에러: 첫 번째 PdhCollectQueryData 실패 (오류 코드: 0x%lx)\n", status);
        PdhCloseQuery(hQuery);
        fclose(logFile);
        return 1;
    }

    // 무한 루프로 5초마다 CPU 사용량 기록
    while (TRUE) { // 무한 루프. Ctrl+C로 종료 가능.
        // 5. 시간 정보 가져오기
        time(&rawTime);
        timeInfo = localtime(&rawTime);
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeInfo);

        // 6. 현재 데이터 샘플 수집
        // PdhCollectQueryData를 호출하여 현재 시점의 성능 데이터를 업데이트합니다.
        status = PdhCollectQueryData(hQuery);
        if (status != ERROR_SUCCESS) {
            printf("경고: PdhCollectQueryData 실패 (오류 코드: 0x%lx). 데이터를 기록하지 못합니다.\n", status);
            // 에러가 발생해도 계속 시도하도록 처리 (일시적 문제일 수 있으므로)
        } else {
            PDH_FMT_COUNTERVALUE counterValue;
            // 7. 카운터 값 포맷팅
            // PdhGetFormattedCounterValue는 수집된 데이터를 읽기 쉬운 형식 (여기서는 double)으로 변환합니다.
            // PDH_FMT_DOUBLE은 실수형으로 값을 받겠다는 의미입니다.
            status = PdhGetFormattedCounterValue(hCounter, PDH_FMT_DOUBLE | PDH_FMT_NOCAP100, NULL, &counterValue);
            if (status != ERROR_SUCCESS) {
                printf("경고: PdhGetFormattedCounterValue 실패 (오류 코드: 0x%lx). 데이터를 기록하지 못합니다.\n", status);
            } else {
                // 8. 파일에 기록
                // %Processor Time은 기본적으로 100%까지 표시되지만, 듀얼 코어 등에서 100%를 초과하는 경우가 있어, PDH_FMT_NOCAP100을 사용하면 이 제한을 해제할 수 있습니다.
                // 일반적인 사용 시에는 필요 없을 수 있습니다.
                fprintf(logFile, "%s, %.2f\n", timestamp, counterValue.doubleValue);
                fflush(logFile); // 즉시 파일에 쓰기
                printf("로그 기록 완료: %s, %.2f\n", timestamp, counterValue.doubleValue);
            }
        }
        // 9. 지정된 시간만큼 대기
        Sleep(INTERVAL_SECONDS * 1000); // 밀리초 단위
    }

    // 10. 자원 해제 (루프가 무한히 돌기 때문에 여기 코드는 실행되지 않지만, 완전한 코드 구성을 위해 포함)
    PdhCloseQuery(hQuery);
    fclose(logFile);

    return 0;
}