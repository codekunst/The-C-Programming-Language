#include <stdio.h>

#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP 20   /* step size */

/* print Fahrenheit-Celsius table */

int main(void) {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3d%6.1f\n", fahr, (5. / 9.) * (fahr - 32.));
    }

    return 0;
}
