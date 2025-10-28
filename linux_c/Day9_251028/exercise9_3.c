#include <stdio.h>

void printf_ary(int(*pa)[4]);

int main (void){

int arr[] = {{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12}};
print_ary(&arr);

}

void print_ary(int (*pa)[4]){

int i, j;

for (i = 0; i < 3; i++){
    for (j = 0; j < 4; j++){
        printf("%5d", pa[i][j]);
    }
printf ("\n");
}

}