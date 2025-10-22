#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void) {

double data[360];
int i, min_index1, min_index2, min_index3 = 1;
double min_value1, min_value2, min_value3;

srand(time(NULL));

for (i = 0; i <= 360; i++){

    data[i] = rand() % 500;
     
 }

min_value1 = data[0];
min_value2 = data[0];
min_value3 = data[0];

for (i = 0; i < 36; i++){
    if (data[i] < min_value1){
        min_value3 = min_value2;
        min_value2 = min_value1;
        min_value1 = data[i];
        min_index1 = i;
        }
    else if (min_value1 < min_value2){
        min_value3 = min_value2;
        min_value2 = data[i];
        min_index2 = i;
    }
    else if (min_value2 < min_value3){
        min_value3 = data[i];
        min_index3 = i;
 }
}
printf("\n[라이다 가장 가까운 탐색 결과 (3개)]\n");
printf("가장 가까운 거리: 1번째 : %.2f 2번째 : %.2f cm 3번째 :%.2f cm\n", min_value1, min_value2, min_value3);
printf("장애물 방향: 1번째 : %d 도 2번째 : %d 도 3번째 : %d 도\n", min_index1, min_index2, min_index3);

    return 0;
}