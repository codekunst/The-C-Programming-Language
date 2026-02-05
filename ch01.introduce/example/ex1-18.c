#include <stdio.h>

/* 1-18.
    파일의 각 행에서 뒷부분의 공백과 tab을 제거하고 전체가 공백인 행을 삭제하는
    프로그램을 작성하시오. */

#define MAXSIZE 1000
#define MAXLENGTH 1000

int getlines(char** lines, int index, int lim);
void trim(char** trimmed_lines,
          int* trimmed_lengths,
          int* trimmed_size,
          char** lines,
          int* lengths,
          int size);
void printlines(char** lines, int* lengths, int size);

int main(void) {
    int i, length, trimmed_size;
    char lines[MAXSIZE][MAXLENGTH], trimmed_lines[MAXSIZE][MAXLENGTH];
    char *ptr[MAXSIZE], *trimmed_ptr[MAXSIZE];
    int lengths[MAXSIZE], trimmed_lengths[MAXSIZE];

    for (i = 0; i < MAXSIZE; i++) {
        ptr[i] = lines[i];
        trimmed_ptr[i] = trimmed_lines[i];
    }

    i = 0;

    while (i < MAXSIZE && (length = getlines(ptr, i, MAXLENGTH)) > 0) {
        lengths[i++] = length;
    }

    trim(trimmed_ptr, trimmed_lengths, &trimmed_size, ptr, lengths, i);

    printlines(trimmed_ptr, trimmed_lengths, trimmed_size);

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
        lines[index][i++] = '\n';
        lines[index][i] = '\0';

        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    return i;
}

void trim(char** trimmed_lines,
          int* trimmed_lengths,
          int* trimmed_size,
          char** lines,
          int* lengths,
          int size) {
    int index, trm_size;

    trm_size = 0;

    for (int i = 0; i < size; i++) {
        index = lengths[i] - 2;

        while (index >= 0 &&
               (lines[i][index] == ' ' || lines[i][index] == '\t')) {
            index--;
        }

        if (index < 0) {
            continue;
        }

        for (int j = 0; j < index + 1; j++) {
            trimmed_lines[trm_size][j] = lines[i][j];
        }

        trimmed_lines[trm_size][++index] = '\n';
        trimmed_lines[trm_size][++index] = '\0';
        trimmed_lengths[trm_size++] = index;
    }

    *trimmed_size = trm_size;
}

void printlines(char** lines, int* lengths, int size) {
    printf("\n**Trimmed Lines**\n");
    printf("Lengths\tSentences\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s", lengths[i], lines[i]);
    }
}
