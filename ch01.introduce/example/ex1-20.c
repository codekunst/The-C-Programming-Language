#include <stdio.h>

/* 1-20.
    파일 중에 있는 tab을 같은 길이의 빈칸으로 대치하는 프로그램을 작성하라.
    매 n번째 위치에 tab 지점이 있다고 가정한다.*/

#define TAPPOSITION 4
#define MAXSIZE 1000
#define MAXLENGTH 1000

int ntab = TAPPOSITION, size = 0;
char lines[MAXSIZE][MAXLENGTH], output[MAXSIZE][MAXLENGTH];

int getlines(void);
void convert(void);
void printlines(void);

int main(void) {
    extern int size;

    size = 0;

    while (size < MAXSIZE && getlines() > 0) {
        size++;
    }

    convert();

    printlines();

    return 0;
}

int getlines(void) {
    int i, c;
    extern int size;
    extern char lines[][MAXLENGTH];

    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
        lines[size][i] = c;
    }

    if (c == '\n') {
        lines[size][i++] = '\n';
        lines[size][i] = '\0';
    }

    if (c == EOF) {
        lines[size][i] = '\0';
    }

    if (c != '\n' && c != EOF) {
        lines[size][i++] = '\n';
        lines[size][i] = '\0';

        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    return i;
}

void convert(void) {
    int i, j;
    extern int size, ntab;
    extern char lines[][MAXLENGTH], output[][MAXLENGTH];

    for (i = 0; i < size; i++) {
        for (j = 0; j < ntab; j++) {
            output[i][j] = lines[i][j];
        }

        output[i][ntab] = output[i][ntab + 1] = output[i][ntab + 2] =
            output[i][ntab + 3] = ' ';

        j = ntab + 1;

        while ((output[i][j + 3] = lines[i][j]) != '\0') {
            j++;
        }
    }
}

void printlines(void) {
    int i;
    extern int ntab, size;
    extern char output[][MAXLENGTH];

    printf("\n**Output (%dth tab to space)**\n", ntab);

    for (i = 0; i < size; i++) {
        printf("%s", output[i]);
    }
}