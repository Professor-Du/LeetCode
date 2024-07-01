#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int m = n + 1, *a = malloc(m * sizeof (int)), b[] = {0,1,1,2};

    memcpy(a, b, fmin(m, 4) * sizeof (int));

    for (int i = 4, j = 0; i < m; i++, j++) {
        if ((i & (i - 1)) == 0) {
            j = 0;
        }
        a[i] = a[j] + 1;
    }

    *returnSize = m;
    return a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits_better(int n, int* returnSize) {
    int m = n + 1, *a = malloc(m * sizeof (int));

    a[0] = 0;

    for (int i = 1, j = 0; i < m; i++, j++) {
        if ((i & (i - 1)) == 0) {
            j = 0;
        }
        a[i] = a[j] + 1;
    }

    *returnSize = m;
    return a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits_better02(int n, int* returnSize) {
    int m = n + 1, *a = malloc(m * sizeof (int));

    a[0] = 0;

    for (int i = 1; i < m; i++) {
        a[i] = a[i >> 1] + (i & 1);
    }

    *returnSize = m;
    return a;
}

int countOnes(int n) {
  int cnt = 0;
  while (n > 0) {
    cnt++;
    n &= n - 1;
  }
  return cnt;
}

int* countBits_best(int n, int* returnSize) {
    int m = n + 1, *a = malloc(m * sizeof (int));

    for (int i = 0, j = 0; i < m; i++, j++) {
        a[i] = countOnes(i);
    }

    *returnSize = m;
    return a;
}

int main () {
    int n = 36, returnSize, *a, *b;

    printf ("input: %d  output:", n);

    b = countBits_best (n, &returnSize);
    a = countBits (n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
      printf (" %d", a[i]);
      if (a[i] != b[i]) {
        printf ("!!!error!!!");
        break;
      }
    }

    free(a);
    free(b);
    getchar ();
    return 0;
}