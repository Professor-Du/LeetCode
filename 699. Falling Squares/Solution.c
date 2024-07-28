#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

#define LEFT  0
#define SIDE  1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fallingSquares(int** positions, int positionsSize) {  // Faster than 100% solutions!!!
    // int *hight = malloc (sizeof (int) * positionsSize), *maxHight = malloc (sizeof (int) * positionsSize);
    int hight[positionsSize], *maxHight = malloc (sizeof (int) * positionsSize);

    hight[0] = positions[0][SIDE];
    maxHight[0] = hight[0];

    for (int i = 1; i < positionsSize; i++) {
        hight[i] = positions[i][SIDE];

        for (int j = 0; j < i; j++) {
            if (positions[i][LEFT] < positions[j][LEFT]) {
                if (positions[j][LEFT] - positions[i][LEFT] < positions[i][SIDE]) {
                    hight[i] = fmax (hight[i], positions[i][SIDE] + hight[j]);
                }
            } else {
                if (positions[i][LEFT] - positions[j][LEFT] < positions[j][SIDE]) {
                    hight[i] = fmax (hight[i], positions[i][SIDE] + hight[j]);
                }
            }
        }
        maxHight[i] = fmax (maxHight[i - 1], hight[i]);
    }

    return maxHight;
}

int main () {
  int a[][2] = {{1,2},{2,3},{6,1}};
  int **p = malloc (sizeof (int *) * ARRAY_SIZE (a));

  printf ("input: {");
  for (int i = 0; i < ARRAY_SIZE (a); i++) {
    p[i] = a[i];
    printf ("{");
    for (int j = 0; j < ARRAY_SIZE (a[0]); j++) {
      printf ("%d ", a[i][j]);
    }
    printf ("} ");
  }
  printf ("} ");

  printf (" output: ");
  int *hight = fallingSquares (p, ARRAY_SIZE (a));
  for (int i = 0; i < ARRAY_SIZE (a); i++) {
    printf ("%d ", hight[i]);
  }
  printf ("\n");

  getchar ();
  return 0;
}
