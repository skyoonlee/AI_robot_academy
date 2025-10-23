# include<stdio.h>

int main(void){

int N;// 센서 개수

printf("센서 개수 :");
scanf("%d", &N);

int value[N]; //센서마다 들어오는 값
int label[1024] = {1};
int black_count = 0; // 라인을 감지한 센서 개수
double index_avg = 0.00; // 라인 중심 위치
int threshold;
int i, j, k, u;
int count = 0;
int sum = 0;
int label_size = 0;
double value_size, sum_index, sum_value = 0.00;

printf("센서마다 들어오는 값 : ");
for(u=0; u<N; u++){
scanf("%d", &value[u]);
}

printf("임계값 입력 :");
scanf("%d", &threshold);

for(i = 0; i < 1024; i++){
    if(i >= threshold){
    label[i] = 0;
}
label_size ++;
}

for (u=0; u<N; u++){
if (value[u]>threshold){
value[u] = 0;
black_count ++;

}

else {
    value[u] = 1;
}

}

for (u=1; u<N; u++){
if (value[u] == 1){
 sum_index += u * value[u];
}
}

index_avg = sum_index / black_count;

printf("label : ");

for(i=0;i<N;i++){
printf("%d\t", value[i]);
}

printf("\n black_count : %d\n", black_count);
printf("index_avg = %.2lf\n", index_avg);


return 0;

}