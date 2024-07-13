#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

static int cmp (const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int findLHS(int* nums, int numsSize){
    int maxLen = 0;

    qsort (nums, numsSize, sizeof (int), cmp);

    for (int i = 0, j = 0; j < numsSize; j++) {
        while (nums[j] > nums[i] + 1) {
            i++;
        }
        if (nums[j] == nums[i] + 1) {
            maxLen = fmax (maxLen, j - i + 1);
        }
    }

    return maxLen;
}

int main () {
  int nums[] = {-14,-13,1,1,1,1,3,4};

  printf ("input: ");
  for (int i = 0; i < ARRAY_SIZE (nums); i++) {
    printf ("%d ", nums[i]);
  }

  printf (" output: %d\n", findLHS (nums, ARRAY_SIZE (nums)));

  getchar ();
  return 0;
}