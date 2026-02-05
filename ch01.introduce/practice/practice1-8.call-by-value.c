#include <stdio.h>

/* power: raise base to n-th power; n >= 0; version 2
 * call by value
 *   지역변수 n 값을 변화시키더라도 main의 n에는 영향을 줄 수 없다.
 * call by reference
 *   포인터, 배열 */

int power(int m, int n);

int main(void) {
    for (int i = 0; i < 10; i++) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    return 0;
}

int power(int base, int n) {
    int p;

    for (p = 1; n > 0; n--) {
        p *= base;
    }

    return p;
}
