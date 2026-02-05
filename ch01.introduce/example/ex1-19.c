#include <stdio.h>

/* 1-19.
    문자열 s의 문자 순서를 뒤집는 프로그램을 작성하라.
    이 함수에 reverse라고 이름 붙이고, 이 함수를 사용해서 파일의 한 행씩 순서를
    뒤집는 프로그램을 작성하라.*/

#define MAXSIZE 1000
#define MAXLENGTH 1000

int getlines(char* line, int lim);
void reverse(char* reversed, int* reversed_length, char* line, int length);
void printlines(char** reversed, int* reversed_lengths, int size);

int main(void) {
    int i, length, size;
    char lines[MAXSIZE][MAXLENGTH], reversed_lines[MAXSIZE][MAXLENGTH];
    char *ptr[MAXSIZE], *reversed_ptr[MAXSIZE];
    int lengths[MAXSIZE], reversed_lengths[MAXSIZE];

    for (i = 0; i < MAXSIZE; i++) {
        ptr[i] = lines[i];
        reversed_ptr[i] = reversed_lines[i];
    }

    size = 0;

    while (size < MAXSIZE && (length = getlines(ptr[size], MAXLENGTH)) > 0) {
        lengths[size++] = length;
    }

    for (i = 0; i < size; i++) {
        reverse(reversed_ptr[i], &reversed_lengths[i], ptr[i], lengths[i]);
    }

    printlines(reversed_ptr, reversed_lengths, size);

    return 0;
}

int getlines(char* line, int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i++] = c;
        line[i] = '\0';
    }

    if (c == EOF) {
        line[i] = '\0';
    }

    if (c != '\n' && c != EOF) {
        line[i++] = '\n';
        line[i] = '\0';

        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    return i;
}

void reverse(char* reversed, int* reversed_length, char* line, int length) {
    for (int i = 0; i < length - 1; i++) {
        reversed[i] = line[length - 2 - i];
    }

    reversed[length - 1] = line[length - 1];
    reversed[length] = line[length];

    *reversed_length = length;
}

void printlines(char** reversed, int* reversed_lengths, int size) {
    printf("\n**Reversed Sentence**\n");
    printf("Length\tSentence\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s", reversed_lengths[i], reversed[i]);
    }
}