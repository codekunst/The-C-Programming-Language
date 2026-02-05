#include <stdio.h>

#define MAXLINE 1000  // maximum input line size

int max;                // maxsimum length seen so far
char line[MAXLINE];     // current input line
char longest[MAXLINE];  // longest line saved here

int getlines(void);
void copy(void);

/* print longest input line; specialized version */
int main(void) {
    int len;
    extern int max;
    extern char longest[];

    max = 0;

    while ((len = getlines()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

/* getlines: specialized version */
int getlines(void) {
    int i, c;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
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

/* copy: specialized version */
void copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;

    while ((longest[i] = line[i]) != '\0') {
        i++;
    }
}