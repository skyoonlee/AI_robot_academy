#include <stdio.h>
#include <math.h>



int main() {

    double x, y;
    printf("실수 x 입력: ");
    scanf("%lf", &x);
    printf("실수 y 입력: ");
    scanf("%lf", &y);

    printf("sqrt(4) = %f\n", sqrt(4));
    printf("pow(2, 3) = %f\n", pow(2, 3));
    printf("sin(x) = %.4f\n", sin(x));
    printf("cos(x) = %.4f\n", cos(x));
    printf("log(x) = %.4f\n", log(x));
    printf("fabs(x) = %.4f\n", fabs(x));
    return 0;

}