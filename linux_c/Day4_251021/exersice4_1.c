#include <stdio.h>
#include <math.h>


extern double sin(double x);
extern double tan(double x);

float clip(float value, float min, float max){
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

int main(void){

    int motor_n;
    double mass, torque, rgr, eta, rad, rrc, sf = 0;
    double tot_t, avail_f, need_f, sin_max, grade, sin_theta, tan_theta, angle;
    
    const double g = 9.81;
    
    printf("경사각 θ (degree): ");
    scanf("%lf", &angle);

    printf("총 질량 m (kg): ");
    scanf("%lf", &mass);

    printf("모터 정격토크 Tm (N.m): ");
    scanf("%lf", &torque);

    printf("구동 모터 수 Nm [개]: ");
    scanf("%d", &motor_n);

    printf("감속비 G: ");
    scanf("%lf", &rgr);

    printf("구동 효율 η (0-1): ");
    scanf("%lf", &eta);

    printf("바퀴 반지름 r (m): ");
    scanf("%lf", &rad);

    printf("구름계수 c(예:0.015-0.03): ");
    scanf("%lf", &rrc);

    printf("안전계수 SF (>=1): ");
    scanf("%lf", &sf);

    if (mass <= 0 || torque <= 0 || motor_n <= 0 || rgr <= 0 || eta <= 0 || eta > 1 || rad <= 0 || rrc < 0 || sf < 1) {
        printf("입력값 범위를 확인하세요.\n");
        return 1;
    }

    sin_theta = sin((angle * M_PI) / 180.0);
    tan_theta = tan((angle * M_PI) / 180.0);

    tot_t = motor_n * torque * rgr * eta;
    avail_f = tot_t / rad;
    need_f = (sin_theta * mass * g) + (rrc * mass * g);
    sin_max = clip((avail_f / (sf - rrc * mass * g))/(mass * g), 0, 1);
    grade = tan_theta * 100.0;


    printf("최대 견인력 F_avail: %.2f N\n", avail_f);
    printf("최대 경사각도 sinθ_max: %.4f\n", sin_max);
    printf("필요 견인력 F_need: %.2f N\n", need_f);
    printf("등판율 (grade): %.2f %%\n", grade);


    return 0;

    }