#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]))

int removeElement(int* nums, int numsSize, int val) {  // Faster than 100% solutions!!!
    int n = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[n++] = nums[i];
        }
    }
    return n;
}

int main () {
  int n, val = 2, nums[] = {0,1,2,2,3,0,4,2};

  printf ("input: ");
  for (int i = 0; i < ARRAY_SIZE (nums); i++) {
    printf ("%d ", nums[i]);
  }

  printf (" output: ");

  n = removeElement (nums, ARRAY_SIZE (nums), val);
  for (int i = 0; i < n; i++) {
    printf ("%d ", nums[i]);
  }

  getchar ();
  return 0;
}