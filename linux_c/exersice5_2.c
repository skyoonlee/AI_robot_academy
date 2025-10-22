#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int remain, N, i;
    double battery[100];
    int warning = 0; // 0: OFF, 1: ON


    printf("데이터 개수 :");
    scanf("%d" , &N);

    srand(time(NULL));
    
    for (i=0; i < N; i++){
    remain = rand() %101;
    battery[i] = remain;
    printf("%d", remain);
    }

    printf("\n[배터리 히스테리시스 경보 결과]\n");
    for( i = 0; i < N; i++){
if (warning == 0 && battery[i] <= 30.0){
    warning = 1;
}
else if (warning == 1 && battery[i] >= 35.0){
    warning = 0;
}

printf("%2d번째 -> 잔량: %5.1f%% | 경고 상태: %s\n", i+1, battery[i], (warning == 1) ? "ON" : "OFF");

    }
    
return 0;

}