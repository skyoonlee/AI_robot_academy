#include <stdio.h>
#include <string.h>

int main(void){


char str[20] = "mango tree";

strncpy(str+6,"apple-pie", 5);

printf("%s\n", str);

return 0;

}