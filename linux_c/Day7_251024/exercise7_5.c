#include <stdio.h>

void print_ary(int *pa, int size);

int main(void)
{

    int ary1[5] = {10, 20, 30, 40, 50};
    int ary2[7] = {10, 20, 30, 40, 50, 60, 70};

    int size = sizeof(arr) / sizeof(arr[0]);

    print_ary(ary1,size);
    printf("\n");
    print_ary(ary2,size);

    return 0;
    
}

void print_ary(int *pa, int size)
{
    int i;

    
    for (i=0; i < size; i++){

        printf("%d ", pa[i]);

    }

}



