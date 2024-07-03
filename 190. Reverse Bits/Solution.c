#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define uint32_t      __UINT32_TYPE__

uint32_t reverseBits (uint32_t n) {  // Faster than 100% solutions!!!
    uint32_t s = 0, cnt = 32;

    while (cnt > 0) {
        s = (s << 1) + (n & 1);
        n >>= 1;
        cnt--;
    }

    return s;
}

/**
 * bits: b0, b1
 * mask: 0x01
 * left: 0, b0; right: b1, 0
 * combine: b1, b0
 */
uint32_t reverseBits_best (uint32_t n) {
    uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
    uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
    uint32_t M4 = 0x0F0F0F0F;  // 00001111000011110000111100001111
    uint32_t M8 = 0x00FF00FF;  // 00000000111111110000000011111111

    n = ((n >> 1) & M1) | ((n & M1) << 1);
    n = ((n >> 2) & M2) | ((n & M2) << 2);
    n = ((n >> 4) & M4) | ((n & M4) << 4);
    n = ((n >> 8) & M8) | ((n & M8) << 8);
    n = (n >> 16) | (n << 16);

    return n;
}

void printBits (uint32_t n) {
  int cnt = 31;
  uint32_t temp = n;

  printf ("%d(", n);
  while (cnt >= 0) {
    printf ("%d", (temp & (1 << cnt)) == 0 ? 0 : 1);
    cnt--;
  }
  printf (")");
}

int main () {
  uint32_t n = 43261596;

  printf ("input: ");
  printBits (n);

  printf ("  output: ");
  printBits (reverseBits_best(n));

  getchar ();
  return 0;
}
