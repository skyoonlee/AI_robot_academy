#include<stdio.h>
#include<math.h>
#include<time.h>

int main(void) {   
int i;
int delta_count = 0;
int gamma_count = 0;
int delta;
int N;


printf("횟수 입력 :");
scanf ("%d", &N);

int speed[N];

srand(time(NULL));

int base = rand() %180;
int offset = rand() %21-10;

speed[0] = base;



for (i = 1; i < N; i++){
    speed[i] = speed[i-1] + offset;
    }

for (i = 0; i < N; i++){
    printf ("speed[%d] : %d km/h\n", i, speed[i]);
    }
    

return 0;
}