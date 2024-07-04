#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **p = malloc (sizeof (int *) * numRows);

    *returnSize = numRows;
    *returnColumnSizes = malloc (sizeof (int) * numRows);

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        p[i] = malloc (sizeof (int) * (*returnColumnSizes)[i]);
        p[i][0] = p[i][i] = 1;
        for (int j = 1; j < i; j++) {
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
        }
    }

    return p;
}

void display (int **vals, int *colSize, int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize[i]; j++) {
            printf ("%d ", vals[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

int main () {
  int n = 19;
  int **vals = NULL, *colSize = NULL, row = 0;

  printf ("input: %d  output:\n", n);

  vals = generate (n, &row, &colSize);

  display (vals, colSize, row);

  getchar ();
  return 0;
}