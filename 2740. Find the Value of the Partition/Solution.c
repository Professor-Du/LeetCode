static int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int findValueOfPartition(int* nums, int numsSize){
  int i, minVal = INT_MAX;

  qsort (nums, numsSize, sizeof (int), cmp);

  for (i = 1; i < numsSize; i++) {
    minVal = fmin (minVal, nums[i] - nums[i - 1]);
  }

  return minVal;
}