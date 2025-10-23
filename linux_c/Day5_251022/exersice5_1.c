#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void) {   
int i;
int delta_count = 0;
int gamma_count = 0;
int delta=0;
int N;
int d_count_10=0;
int g_count_10=0;

printf("횟수 입력 :");
scanf ("%d", &N);

int speed[N];

srand(time(NULL));

int base = rand() %180;
int offset = rand() %21-10;

speed[0] = base;



for (i = 1; i < N; i++){
    speed[i] = speed[i-1] + offset;
    if(0 < speed[i]-speed[i-1]){
        delta_count ++;
        if (delta_count == 10){
            d_count_10 ++;
        }

    }
    else if (0 > speed[i]-speed[i-1]){
        gamma_count ++;  
        if (gamma_count == 10){
            g_count_10 ++;   
    }

}



for (i = 0; i < N; i++){
    printf ("speed[%d] : %d km/h\n", i, speed[i]);
}
    
printf("10회 연속 가속 횟수 : %d", d_count_10);
printf("10회 연속 감속 횟수 : %d", g_count_10);
}
return 0;
}