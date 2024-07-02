#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x) {  // Faster than 100% solutions!!!
    long long s, mid, left = 0, right = x;

    while (left < right) {
        mid = (left + right + 1) / 2;
        s = mid * mid;
        if (x < s) {
            right = mid - 1;
        } else if (x > s) {
            left = mid;
        } else {
            return mid;
        }
    }

    return right;
}

int main () {
    int x = 2147483647;

    printf ("input: %d  output: %d\n", x, mySqrt (x));

    getchar ();
    return 0;
}
