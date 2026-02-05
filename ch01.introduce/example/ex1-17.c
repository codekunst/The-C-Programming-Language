#include <stdio.h>

/* 1-17.
    길이가 80자 이상인 모든 행을 출력하는 프로그램을 작성하라. */

#define MAXSIZE 1000
#define MAXLENGTH 1000
#define THRESHOLD 80

int getlines(char** lines, int index, int lim);
void printlines(char** lines, int* lengths, int size, int threshold);

int main(void) {
    int i, length;
    char lines[MAXSIZE][MAXLENGTH];
    char* ptr[MAXSIZE];
    int lengths[MAXSIZE];

    for (i = 0; i < MAXSIZE; i++) {
        ptr[i] = lines[i];
    }

    i = 0;

    while (i < MAXSIZE && (length = getlines(ptr, i, MAXLENGTH)) > 0) {
        lengths[i++] = length;
    }

    printlines(ptr, lengths, i, THRESHOLD);

    return 0;
}

int getlines(char** lines, int index, int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        lines[index][i] = c;
    }

    if (c == '\n') {
        lines[index][i++] = c;
        lines[index][i] = '\0';
    }

    if (c == EOF) {
        lines[index][i] = '\0';
    }

    if (c != '\n' && c != EOF) {
        lines[index][i - 1] = '\n';
        lines[index][i++] = '\0';

        while ((c != getchar()) != '\n' && c != EOF) {
        }
    }

    return i;
}

void printlines(char** lines, int* lengths, int size, int threshold) {
    printf("\n**Lines such that length over %d**\n", threshold);
    printf("Lengths\tSentences\n");

    for (int i = 0; i < size; i++) {
        if (lengths[i] >= threshold) {
            printf("%d\t%s", lengths[i], lines[i]);
        }
    }
}