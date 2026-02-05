#include <stdio.h>

/* 1-16.
    문자열을 입력받고 모든 행의 길이와 문자를 출력하시오. */

#define MAXSIZE 1000
#define MAXLENGTH 1000

int getlines(char** lines, int index, int maxlength);
void printlines(char** lines, int* lengths, int size);

int main(void) {
    int size, length;
    char lines[MAXSIZE][MAXLENGTH];
    char* ptr[MAXSIZE];
    int lengths[MAXSIZE];

    size = 0;

    for (int i = 0; i < MAXSIZE; i++) {
        ptr[i] = lines[i];
    }

    while (size < MAXSIZE && (length = getlines(ptr, size, MAXLENGTH)) > 0) {
        lengths[size++] = length;
    }

    printlines(ptr, lengths, size);

    return 0;
}

int getlines(char** lines, int index, int maxlength) {
    int c, i;

    for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        lines[index][i] = c;
    }

    if (c == '\n') {
        lines[index][i++] = c;
        lines[index][i] = '\0';
    }

    if (c == EOF) {
        lines[index][i] = '\0';
    }

    if (c != EOF && c != '\n') {
        lines[index][i - 1] = '\n';
        lines[index][i] = '\0';

        while ((c = getchar()) != EOF && c != '\n') {
        }
    }

    return i;
}

void printlines(char** lines, int* lengths, int size) {
    printf("\nLength\tSentence\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s", lengths[i], lines[i]);
    }
}