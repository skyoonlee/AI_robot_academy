#include <stdio.h>

int main(void){

int a;
a = 10;

int *pa;

pa = &a;

printf ("포인터 pa에 변수 a 대입 결과값: %d\n", *pa);

*pa = 20;

printf ("포인터 pa에 간접 참조 연산자 대입 결과값 : %d\n", *pa);

return 0;
}