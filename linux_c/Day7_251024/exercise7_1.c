#include <stdio.h>

int main(void)
{
int a = 10;
int *p = &a;
double *pd;
pd = (double*)p;
printf("*pd가 가르키는 값 : %d\n", *pd); // pd안에는 double*p의 주소값이 들어있음
printf("pd의 값 : %d\n", pd); // pd의 값
printf("*pd의 주소 : %u\n", *pd); // pd
printf("pd의 주소 : %u\n", pd);
printf("형변환 a의 값 : %d\n", (int)a);
// (형변환)pd 가 안되는 이유는 포인터 자체의 타입은 unsigned int라서
printf("형변환 (*pd)의 값 : %lf\n", (double)*pd);
printf("(형변환*)pd의 값 : %lf\n", (double*)pd);

printf("*p의 값 : %lf\n", *p);
printf("p의 값 : %lf\n", p);
printf("*p의 주소 값 : %u\n", *p);
printf("p의 주소 값: %u\n", p);

printf("포인터 pd의 크기 : %d",sizeof((double)*pd));
printf("포인터 pd의 크기 : %d",sizeof((double)*p));
return 0;

}