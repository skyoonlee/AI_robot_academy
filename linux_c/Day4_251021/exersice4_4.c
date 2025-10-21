#include <stdio.h>

int sum_num(int count);
int total = 0;

int main(void) {

    printf("%d\n", sum_num(1));

    return 0;

}

int sum_num(int count) {
    if(count == 10) return;
    total = count += sum_num(count + 1);
}
