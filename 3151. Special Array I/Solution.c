bool isArraySpecial(int* nums, int numsSize) {
  for (int i = 1; i < numsSize; i++) {
    // if ((nums[i] & 1) == (nums[i - 1] & 1)) {
    if (((nums[i] ^ nums[i - 1]) & 1) == 0) {
      return false;
    }
  }

  return true;
}