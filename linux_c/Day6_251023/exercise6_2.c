#include<stdio.h>

int main(void){

    int N, i;

    double Vref, k = 0.00;
    
    

printf("N = ");
scanf("%d", &N);


double adc[N];
printf("adc = ");
for(i=0; i < N; i++){
scanf("%lf", &adc[i]);
}

printf("Vref = ");
scanf("%lf", &Vref);

printf("k = ");
scanf("%lf", &k);


printf("\nADC \t -> ");
for (i=0; i<N; i++){
printf("%.0lf ", adc[i]);
}



double voltage, distance = 0.00;
double dist[N];



printf("\n전압(V) \t -> ");
for (i=0; i<N; i++){
    voltage = (adc[i] / 1023) * Vref;
    dist[i] = k * (1 / voltage);

    printf("%.2lf  ",voltage);
}

printf("\n거리(cm) \t -> ");
for (i=0; i<N; i++){
    printf("%.2lf  ",dist[i]);
}

return 0;
}