#include <stdio.h>

/* 1-13.
 *   입력된 단어의 길이에 대한 히스토그램을 작성하는 프로그램을 작성하라. */

#define IN 0
#define OUT 1
#define CAPACITY 10

int main(void) {
    int c, length, max_count, status;

    int length_counts[CAPACITY];

    length = max_count = 0;
    status = OUT;

    for (int i = 0; i < 10; i++) {
        length_counts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (status == IN) {
                length_counts[length]++;

                max_count = length_counts[length] > max_count
                                ? length_counts[length]
                                : max_count;

                length = 0;
                status = OUT;
            }
            continue;
        }

        if (status == OUT) {
            status = IN;
        }

        length++;
    }

    printf("\n\n[Histogram] Length of words\n\n");

    for (int i = 0; i < max_count; i++) {
        for (int j = 0; j < CAPACITY; j++) {
            putchar(' ');
            putchar(max_count - i > length_counts[j] ? ' ' : '*');
            putchar(' ');
        }
        putchar('\n');
    }

    for (int i = 0; i < CAPACITY; i++) {
        putchar(' ');
        putchar('-');
        putchar(' ');
    }

    putchar('\n');

    for (int i = 0; i < CAPACITY; i++) {
        putchar(' ');
        putchar(i + '0');
        putchar(' ');
    }

    putchar('\n');

    return 0;
}