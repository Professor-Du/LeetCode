#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]))

int removeDuplicates(int* nums, int numsSize) {
    int n = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[n-1]) {
            nums[n++] = nums[i];
        }
    }
    return n;
}

int main () {
  int n, nums[] = {0,0,1,1,1,2,2,3,3,4};

  printf ("input: ");
  for (int i = 0; i < ARRAY_SIZE (nums); i++) {
    printf ("%d ", nums[i]);
  }

  printf (" output: ");

  n = removeDuplicates (nums, ARRAY_SIZE (nums));
  for (int i = 0; i < n; i++) {
    printf ("%d ", nums[i]);
  }

  getchar ();
  return 0;
}