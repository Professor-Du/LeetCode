#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/

typedef struct {
    int val[0];
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    int n = sizeof (int) * numsSize;
    NumArray *p = malloc (n);
    
    memcpy (p->val, nums, n);

    return p;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;

    for (int i = left; i <= right; i++) {
        sum += obj->val[i];
    }

    return sum;
}

NumArray* numArrayCreate_best(int* nums, int numsSize) {
    NumArray *p = malloc (sizeof (int) * (numsSize + 1));
  
    p->val[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
      p->val[i] = p->val[i - 1] + nums[i - 1];  // preSum
    }

    return p;
}

int numArraySumRange_best(NumArray* obj, int left, int right) {
    return obj->val[right + 1] - obj->val[left];
}

void numArrayFree(NumArray* obj) {
    free (obj);
}


int main () {
  int nums[] = {-2,0,3,-5,2,-1}, left = 2, right = 5;  // preSum = [-2, -2, 1, -4, -2, -3]
  NumArray *obj;

  printf ("input: ");
  for (int i = 0; i < ARRAY_SIZE (nums); i++) {
    printf ("%d ", nums[i]);
  }

  obj = numArrayCreate_best (nums, ARRAY_SIZE (nums));

  printf (" output: sum(%d,%d) = %d\n", left, right, numArraySumRange_best (obj, left, right));

  numArrayFree (obj);

  getchar ();
  return 0;
}

