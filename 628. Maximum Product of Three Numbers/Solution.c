static int cmp (const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

int maximumProduct(int* nums, int numsSize) {
  qsort (nums, numsSize, sizeof (int), cmp);
  return fmax (nums[0] * nums[1] *nums[2], nums[0] * nums[numsSize - 1] * nums[numsSize - 2]);
}