

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){  // Faster than 100% solutions!!!
  int i, val, *arr = malloc (sizeof (int) * n);

  for (i = 1; i < n; i += 2) {
    arr[i] = i;
    arr[i - 1] = -i;
  }
  if((n & 1) != 0) {
    arr[n - 1] = 0;
  }

  *returnSize = n;
  return arr;
}