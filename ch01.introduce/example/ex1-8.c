#include <stdio.h>

int main(void) {
    int c, ne, nt, nl;

    ne = 0;
    nt = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ne++;
            continue;
        }

        if (c == '\t') {
            nt++;
            continue;
        }

        if (c == '\n') {
            nl++;
            continue;
        }
    }

    printf("빈칸: %d개, 탭: %d개, 행: %d개\n", ne, nt, nl);

    return 0;
}