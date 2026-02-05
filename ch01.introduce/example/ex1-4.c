#include <stdio.h>

/*
  print Celsius-Fahrenheit table
  for celsius = 0, 30, ..., 300; floating-point ver.
*/

int main(void) {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;   /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 30;   /* step size */

    celsius = lower;

    printf("** Celsius-Fahrenheit table **\n");

    while (celsius <= upper) {
        fahr = (9. / 5.) * celsius + 32.;

        printf("%3.0f%6.1f\n", celsius, fahr);

        celsius += step;
    }

    return 0;
}