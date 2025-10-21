#include <stdio.h>
int main(void) {

    int i, j;

    i = 1;

    while (i < 9){
        i++;
        printf("\n %d 단 \n", i);
        j = 1;
        while (j <= 9){

            printf ("%d x %d = %d\n", i, j, i * j);
            j++;
        }
    }
    return 0;

}