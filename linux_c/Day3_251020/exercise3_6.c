#include <stdio.h>

int main(void) {

    int i, j;

    for (i = 2; i <= 9; i++) {
        printf("\n %d 단 \n", i);
        for (j = 1; j <= 9; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        
    }
}