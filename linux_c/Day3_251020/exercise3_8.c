#include <stdio.h>
int main(void) {

    int a = 5;
    int i ;
    int sum(int x, int y);

    printf("a : %d\n", a);
    printf("sum : %d\n", sum(a,10));
    
    
    return 0;

    }

int sum(int x, int y){
    int result;
    result = x + y;
    return result;
}
