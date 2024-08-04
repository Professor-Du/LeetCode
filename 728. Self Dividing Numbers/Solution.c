/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isSelfDividingNum (int n) {
  int digit, val = n;

  do {
    digit = val % 10;
    if (digit == 0 || (n % digit) != 0) {
      return false;
    }

    val /= 10;
  } while (val > 0);

  return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {  // Faster than 100% solutions!!!
  int i, cnt = 0, *nums = malloc (sizeof (int) * (right - left + 1));
  for (i = left; i <= right; i++) {
    if (isSelfDividingNum (i)) {
      nums[cnt++] = i;
    }
  }

  *returnSize = cnt;
  return nums;
}