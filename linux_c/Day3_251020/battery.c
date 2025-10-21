#include <stdio.h>

float curr = 0;
float vel = 0;
float r = 0;
float v_bat = 0;
float c = 0;
float eta = 0;
float watt = 0;
float motor_count = 0;

float main(void)

{
    printf("-------사전 선정 정보-------\n");
    printf("평균 전류 I_load [A]:");
    scanf("%f", &curr);
  
    
    printf("평균 속도 vel [km/h]:");
    scanf("%f", &vel);


    printf("예비율 R[20'%' = 0.2]:");
    scanf("%f", &r);


    printf("모터의 개수:");
    scanf("%f", &motor_count);


    printf("-------배터리 정보-------\n");
    printf("공칭 전압 V_bat [V]:");
    scanf("%f", &v_bat);
 

    printf("용량 C [Ah]:");
    scanf("%f", &c);


    printf("시스템 효율 eta [90'%' = 0.9]:");
    scanf("%f", &eta);


    if (vel <= 0 || curr <= 0 || v_bat <= 0 || c <= 0 || eta <= 0 || r < 0 || r >= 1) {
        printf("입력 값이 올바르지 않습니다. 모든 값은 양수여야 하며, 예비율 R은 0 이상 1 미만이어야 합니다.\n");
        return 1; 
    }
    
    printf("[결과]");
    float e_avail = v_bat * c * (1 - r) * eta; // 사용 가능 에너지
    printf("사용 가능 에너지 E_avail [Wh]: %.2f\n", e_avail);
    float watt = (v_bat*curr / eta) * motor_count; // 소비전력
    printf("소비전력(W): %.2f\n", watt);
    float runtime = e_avail / watt; // 런타임(시간)
    printf("런타임 t                : %.2f [h] (%.1f) min\n", runtime , (runtime)*60);
    float dimension = vel * runtime; // 주행 거리
    printf("주행 거리 d             : %.2f[km]\n", dimension);
    printf("(계산 가정 : 전압강하/온도영향 무시, 평균전류 일정, 전류는 부하측 기준)");
    return 0;
}