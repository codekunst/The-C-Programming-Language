#include <stdio.h>

#define IN 0
#define OUT 1

int main(void) {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
            continue;
        }

        if (state == OUT) {
            state = IN;
        }

        putchar(c);
    }

    printf("\n");

    return 0;
}