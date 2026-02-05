#include <stdio.h>

/* 1-15.
 *   1.2절의 온도변환 프로그램을 온도변환 함수를 사용해서 다시 작성해 보라.
 *   F = (5 / 9) * (C - 32) */

double fahr_to_celsius(int fahr);
double celsius_to_fahr(int celsius);

int main(void) {
    printf("** Fahrenheit to Celsius\n");
    for (int fahr = 0; fahr <= 300; fahr += 20) {
        printf("fahr: %d > celsius: %.2f\n", fahr, fahr_to_celsius(fahr));
    }

    printf("\n");

    printf("** Celsius to Fahrenheit\n");
    for (int celsius = 0; celsius <= 300; celsius += 20) {
        printf("celsius: %d > fahr: %.2f\n", celsius, celsius_to_fahr(celsius));
    }

    return 0;
}

double fahr_to_celsius(int fahr) {
    return 9. / 5. * fahr + 32.;
}

double celsius_to_fahr(celsius)
int celsius;
{
    return 5. * (celsius - 32.) / 9.;
}