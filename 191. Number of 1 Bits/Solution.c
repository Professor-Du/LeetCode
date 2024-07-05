#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int hammingWeight(int n) {
    int cnt = 0;
    while (n > 0) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

int hammingWeight_best0(int n) {
    int M1 = 0x55555555;
    int M2 = 0x33333333;
    int M4 = 0x0F0F0F0F;
    int M8 = 0x00FF00FF;
    int M16 = 0x0000FFFF;

    n = (n & M1) + ((n >> 1) & M1);    // equals to n - ((n >> 1) & M1);
    n = (n & M2) + ((n >> 2) & M2);
    n = (n & M4) + ((n >> 4) & M4);    // equals to (n + (n >> 4)) & M4, because the number of 1s in every 8 bits is less than 0xF
    n = (n & M8) + ((n >> 8) & M8);    // euqals to (n + n >> 8) & 0x1F, keep the values in higher bits for now.
    n = (n & M16) + ((n >> 16) & M16); // equals to (n + n >> 16) & 0x1F, keep the values in higher bits for now.

    return n;  // n & 0x1F
}

int hammingWeight_best1(int n) {  // Faster than 100% solutions!!!
    int M1 = 0x55555555;
    int M2 = 0x33333333;
    int M4 = 0x0F0F0F0F;

    n = n - ((n >> 1) & M1);           // equals to (n & M1)  + ((n >> 1)  & M1);
    n = (n & M2) + ((n >> 2) & M2);
    n = (n + (n >> 4)) & M4;           // equals to (n & M4)  + ((n >> 4)  & M4);
    n = n + (n >> 8);                  // euqals to (n & M8)  + ((n >> 8)  & M8);
    n = n + (n >> 16);                 // equals to (n & M16) + ((n >> 16) & M16);

    return n & 0x1F;  // n & 0x1F
}

int main () {
  int n = 19;

  printf ("input: %d  output: %d\n", n, hammingWeight_best (n));

  getchar ();
  return 0;
}