#include <stdio.h>

int power(int m, int n);
int power_old();

/*
 * test power function
 * argument of power function: 2, i
 */
int main(void) {
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
        printf("%d %d %d\n", i, power_old(2, i), power_old(-3, i));
    }

    return 0;
}

/*
 * power: raise base to n-th power; n >= 0
 * parameter of power function: base, n
 */
int power(int base, int n) {
    int i, p;

    p = 1;

    for (i = 0; i < n; i++) {
        p *= base;
    }

    return p;
}

/*
 * power_old: raise base to n-th power; n >= 0
 * (old-style version)
 */
power_old(base, n) int base, n;
{
    int i, p;

    p = 1;

    for (i = 0; i < n; i++) {
        p *= base;
    }

    return p;
}