#include <stdio.h>

int main(void)

{
 unsigned int a;

 a = 4294967295;
    printf("%d\n", a);  // %d : signed int
 a = -1;
    printf("%u\n", a);  // %u : unsigned int

    return 0;
}