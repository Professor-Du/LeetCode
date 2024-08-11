int maxProductDifference(int* nums, int numsSize){
  int i, val, max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;

  for (i = 0; i < numsSize; i++) {
    val = nums[i];
    if (val > max1) {
      max2 = max1;
      max1 = val;
    } else if (val > max2) {
      max2 = val;
    }
    if (val < min1) {
      min2 = min1;
      min1 = val;
    } else if (val < min2) {
      min2 = val;
    }
  }

  return max1 * max2 - min1 * min2;
}

static int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int maxProductDifference_02(int* nums, int numsSize){
  qsort (nums, numsSize, sizeof (int), cmp);

  return nums[numsSize - 1] * nums[numsSize - 2] - nums[0] * nums[1];
}