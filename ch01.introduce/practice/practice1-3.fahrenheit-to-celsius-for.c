#include <stdio.h>

/* print Fahrenheit-Celsius table */

int main(void) {
    int fahr;

    printf("** Fahrenheit-Celsius table **\n");

    for (fahr = 0; fahr <= 300; fahr += 20) {
        printf("%3d%6.1f\n", fahr, (5. / 9.) * (fahr - 32.));
    }
}