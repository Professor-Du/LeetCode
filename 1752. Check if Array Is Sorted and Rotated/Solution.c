bool check(int* nums, int numsSize) {  // Faster than 100% solutions!!!
  int i, cnt = 0;
  for (i = 1; i < numsSize; i++) {
    if (nums[i] < nums[i - 1]) {
        if (++cnt > 1) {
            return false;
        }
    }
  }
  return cnt == 0 || nums[0] >= nums[numsSize - 1];
}