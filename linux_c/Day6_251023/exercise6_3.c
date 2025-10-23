#include <stdio.h>

int main(void)
{
int a;
int *pa;

pa = &a; // 포인터에 a의 주소 대입
*pa = 10; // 포인터로 변수 a에 10 대입

printf("포인터로 a 값 출력 :%d\n", *pa);
printf("변수명으로 a 값 출력 :%d\n", a);
printf("포인터의 주소 값 출력 : %u\n", pa);

return 0;
}