#include <stdio.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        printf("%d", c != EOF);

        if (c == '\n') {
            putchar('\n');
        }
    }

    printf("%d\n", c != EOF);

    return 0;
}