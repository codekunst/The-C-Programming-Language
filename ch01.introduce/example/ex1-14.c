#include <stdio.h>

/* 1-14.
 *   입력된 문자들의 사용빈도를 나타내는 히스토그램을 출력하는 프로그램을
 *   작성하라. */

#define ALPHABET_CAPACITY 26
#define DIGIT_CAPACITY 10

int main(void) {
    int c, max_count;
    int alphabet_counts[ALPHABET_CAPACITY], digit_counts[DIGIT_CAPACITY],
        other_counts;

    for (int i = 0; i < ALPHABET_CAPACITY; i++) {
        alphabet_counts[i] = 0;
    }

    for (int i = 0; i < DIGIT_CAPACITY; i++) {
        digit_counts[i] = 0;
    }

    other_counts = 0;

    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z') {
            alphabet_counts[c - 'a']++;
            max_count = alphabet_counts[c - 'a'] > max_count
                            ? alphabet_counts[c - 'a']
                            : max_count;
            continue;
        }

        if ('A' <= c && c <= 'Z') {
            alphabet_counts[c - 'A']++;
            max_count = alphabet_counts[c - 'A'] > max_count
                            ? alphabet_counts[c - 'A']
                            : max_count;
            continue;
        }

        if ('0' <= c && c <= '9') {
            digit_counts[c - '0']++;
            max_count = digit_counts[c - '0'] > max_count
                            ? digit_counts[c - '0']
                            : max_count;
            continue;
        }

        other_counts++;
        max_count = other_counts > max_count ? other_counts : max_count;
    }

    printf("\n\n[Histogram] Count of characters\n\n");

    for (int i = 0; i < max_count; i++) {
        for (int j = 0; j < ALPHABET_CAPACITY; j++) {
            putchar(' ');
            putchar(max_count - i > alphabet_counts[j] ? ' ' : '*');
            putchar(' ');
        }

        for (int j = 0; j < DIGIT_CAPACITY; j++) {
            putchar(' ');
            putchar(max_count - i > digit_counts[j] ? ' ' : '*');
            putchar(' ');
        }

        putchar(' ');
        putchar(max_count - i > other_counts ? ' ' : '*');
        putchar(' ');
        putchar('\n');
    }

    for (int i = 0; i < ALPHABET_CAPACITY + DIGIT_CAPACITY + 1; i++) {
        putchar('-');
        putchar('-');
        putchar('-');
    }

    putchar('\n');

    for (int i = 0; i < ALPHABET_CAPACITY; i++) {
        putchar(' ');
        putchar('a' + i);
        putchar(' ');
    }

    for (int i = 0; i < DIGIT_CAPACITY; i++) {
        putchar(' ');
        putchar('0' + i);
        putchar(' ');
    }

    putchar(' ');
    putchar('O');
    putchar(' ');

    putchar('\n');

    return 0;
}
