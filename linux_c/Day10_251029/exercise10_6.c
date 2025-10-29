#include <stdio.h>

int main(void)
{
FILE *fp;
char str[500];
int i;
int ch;

fp = fopen("log.txt", "r");
if (fp == NULL)
{
    printf("파일이 열리지 않았습니다. \n");
    return 1;
}

i = 0;
while (1){

    ch = fgetc(fp);
    if (ch == EOF){
        break;
    }
    putchar(ch);

}

fclose(fp);

return 0;

}