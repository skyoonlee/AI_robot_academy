#include <stdio.h>

int main(void) {

    float salary;
    float eit, eitr, lit, litr, np, npr, ei, eir, hi, hir;
    float total;

    printf(" This program calculates social insurance tax.\n");
    printf(" Please enter your salary(month): ");
    scanf("%f", &salary);

    eit = salary * ((eitr = 4) / 100.0);
    lit = salary * ((litr = 10) / 100.0);
    np = salary * ((npr = 4.5) / 100.0);
    ei = salary * ((eir = 0.8) / 100.0);
    hi = salary * ((npr = 3.38) / 100.0);
    total = eit + lit + np + ei + hi;

    printf("\nEarned Income Tax: %.10d Won\n", (int)eit);
    printf("Local Income Tax: %.10d Won\n", (int)lit);
    printf("National Pension: %.10d Won\n", (int)np);
    printf("Employment Insurance: %.10d Won\n", (int)ei);
    printf("Health Insurance: %.10d Won\n", (int)hi);
    printf("-----------------------------------\n");
    printf("Total                    : %.10d Won\n", (int)total);

    return 0;
}