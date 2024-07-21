/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {  // solution from comments
  int i, m, *r = malloc (sizeof (int) * 2);
  for (i = 0; i < numsSize; i++) {
    m = abs (nums[i]) - 1;
    if (nums[m] < 0) {
      r[0] = m + 1;
    }
    nums[m] = -nums[m];
  }

  for (i = 0; i < numsSize; i++) {
    if ((nums[i] > 0) && (i + 1 != r[0])) {
      r[1] = i + 1;
      break;
    }
  }
  *returnSize = 2;
  return r;
}