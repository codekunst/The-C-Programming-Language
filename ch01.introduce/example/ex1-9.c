#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == OUT) {
                state = IN;
            }
            continue;
        }

        if (state == IN) {
            putchar(' ');
            state = OUT;
        }

        putchar(c);
    }

    printf("\n");

    return 0;
}