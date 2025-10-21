#include <stdio.h>

int main(void) {

  double wheel_N = 0;
  double total_weight = 0;
  double sf = 0;
  double dm = 0;

  double wheel_R = 0;
  double torque = 0;
  double reducer = 0;

  const double c = 0.018;
  const double g = 9.81;
  double w = 0;
  int result = 0;
  

  printf("기획 단계에서 선정하는 요소\n");
  printf("구동 바퀴 수 : N =");
  scanf("%lfea", &wheel_N);
  printf("총 하중(질량) : m =");
  scanf("%lf[kg]", &total_weight);
  printf("안전계수 : SF (Safety Factor = ");
  scanf("%lf", &sf);
  printf("설계마진 : DM (Design Margin) = ");
  scanf("%lf", &dm);
    
    printf("저항계수 정보\n");
    printf("구름저항계수 : c = %lf\n", c);
    printf("중력가속도 : g = %lf[m/s^2]\n", g);
    w = (total_weight * g);

for(result = 0; result != 1; ) { 

    printf("모터 정보\n");
    printf("바퀴 반지름 : R = ");
    scanf("%lf[m]", &wheel_R);
    printf("모터 토크 : T =");
    scanf("%lf[Nm]", &torque);
    printf("감속비 : i = ");
    scanf("%lf", &reducer);
    


        printf("견인력 계산\n");
       
        double F_min = (c * w * sf * dm);
        double F_motor = ((torque * reducer) / wheel_R)* wheel_N;

        printf("필요한 최소 견인력 F_min : %lf[N]\n", F_min);
        printf("모터가 낼 수 있는 견인력 F_motor : %lf[N]\n", F_motor);
        if (F_motor <= F_min) {
            printf("판정 : 불만족(더 큰 모터나 감속비가 필요합니다.)\n");
        } 
        else {
        printf("판정 : 만족\n");
        result = 1;
        }
}
 
    return 0;

}