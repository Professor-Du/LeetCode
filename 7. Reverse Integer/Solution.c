#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INT_MIN         (1 << 31)     // -2147483648
#define INT_MAX         __INT_MAX__   // 2147483647
#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

int reverse(int x){  // Faster than 100% solutions!!!
    int r = 0;
    bool sign = (x >= 0);
    unsigned int ux = sign ? x : ~(unsigned int)x + 1;

    while (ux > 0) {
        if ((r > INT_MAX / 10) || (r == INT_MAX / 10 && ux % 10 > INT_MAX % 10)) {
            return 0;
        }
        r = r * 10 + ux % 10;
        ux /= 10;
    }

    return sign ? r : -r;
}

int reverse_better(int x){
    int r = 0;

    while (x != 0) {
        if ((r > INT_MAX / 10) || (r < INT_MIN / 10)) {  // ux % 10 can be at most 2 when r == INT_MAX / 10.
            return 0;
        }
        r = r * 10 + x % 10;  // -123 % 10 = -3 in C; -123 % 10 = 7 in Python 2.
        x /= 10;
    }

    return r;
}

int main () {
  int x[] = {1463847412, -2147483648, 1534236469, 123, 120, -123, 123};

  for (int i = 0; i < ARRAY_SIZE (x); i++) {
    printf ("[case %d] input: %-11d  output: %d\n", i, x[i], reverse_better(x[i]));
  }

  getchar ();
  return 0;
}