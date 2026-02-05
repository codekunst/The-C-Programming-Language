#include <stdio.h>

/* copy input to output; 2nd version */

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    putchar('\n');

    fflush(stdout);

    return 0;
}