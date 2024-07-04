#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {  // Faster than 100% solutions!!!
    *returnSize = rowIndex + 1;

    int *p = malloc (sizeof (int) * (*returnSize));

    for (int i = 0; i <= rowIndex; i++) {
        p[0] = p[i] = 1;
        for (int j = i - 1; j > 0; j--) {  // p[i][j] = p[i-1][j-1] + p[i-1][j]; check 877. Stone Game
            p[j] = p[j - 1] + p[j];
        }
    }

    return p;
}

int* getRow_math(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int i, *p = malloc (sizeof (int) * (*returnSize));

    for (i = 1, p[0] = 1; i <= rowIndex; i++) {
        p[i] = p[i-1] * (rowIndex - i + 1) / i;
    }

    return p;
}

void display (int *vals, int num) {
    for (int i = 0; i < num; i++) {
        printf ("%d ", vals[i]);
    }
}

int main () {
  int n = 6;
  int *vals = NULL, num = 0;

  printf ("input: %d  output: ", n);

  vals = getRow_math (n, &num);

  display (vals, num);

  getchar ();
  return 0;
}