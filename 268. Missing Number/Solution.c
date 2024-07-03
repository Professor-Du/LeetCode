#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

int missingNumber(int* nums, int numsSize) {
    int sum = 0, total = (numsSize + 1) * numsSize / 2;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return total - sum;
}

static int cmp (const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

int missingNumber02(int* nums, int numsSize) {
    int i;

    qsort (nums, numsSize, sizeof (int), cmp);

    for (i = 0; i < numsSize; i++) {
      if (nums[i] != i) {
        return i;
      }
    }
    return i;
}

int missingNumber03(int* nums, int numsSize) {
    int i;
    bool *hash = calloc (numsSize + 1, sizeof (int));

    for (i = 0; i < numsSize; i++) {
      hash[nums[i]] = true;
    }

    for (i = 0; i < numsSize; i++) {
      if (!hash[i]) {
        return i;
      }
    }
    return i;
}

int missingNumber04(int* nums, int numsSize) {
    int i, xor = 0;

    for (i = 0; i < numsSize; i++) {
      xor ^= nums[i];
    }

    for (i = 0; i < numsSize + 1; i++) {
      xor ^= i;
    }

    return xor;
}

int main () {
  int a[] = {9,6,4,2,3,5,7,0,1};

  printf ("input: ");
  for (int i = 0; i < ARRAY_SIZE (a); i++) {
    printf ("%d ", a[i]);
  }

  printf (" output: %d\n", missingNumber04 (a, ARRAY_SIZE(a)));

  getchar ();
  return 0;
}