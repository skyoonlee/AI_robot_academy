#include <stdio.h>

int main(void) {

    char str[80];

    printf("문자열 입력 : ");
    gets(str);
    puts("입력한 문자열 : ");
    puts(str);

    return 0;
}