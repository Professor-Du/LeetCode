/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
  int i, j, val, carry = 0, len = fmax (numSize + 1, 5), *arr = malloc (sizeof (int) * len);

  for (i = len - 1, j = numSize - 1; k > 0 || j >= 0 || carry > 0; i--, j--) {
    val = (k % 10) + carry;
    if (j >= 0) {
      val += num[j];
    }

    arr[i] = val %10;
    carry = val / 10;
    k /= 10;
  }

  *returnSize = len - i - 1;
  return arr + i + 1;
}