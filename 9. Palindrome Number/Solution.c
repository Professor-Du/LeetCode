#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int rx = 0, ix = x;

    if (x < 0) {
        return false;
    }

    while (x > 0) {
        if (rx > (__INT_MAX__ - x % 10) / 10) {
            return false;
        }

        rx = rx * 10 + x % 10;
        x /= 10;
    }

    return rx == ix;  // input x equals to reverse x;
}

bool isPalindrome_best(int x) {
    long rx = 0, ix = x;

    if (ix < 0) {
        return false;
    }

    while (x > 0) {
        rx = rx * 10 + x % 10;
        x /= 10;
    }

    return rx == ix;
}

int main () {
  int x = 121;

  printf ("input: %d  output: %s\n", x, isPalindrome_best (x) ? "true" : "false");

  getchar();
  return 0;
}