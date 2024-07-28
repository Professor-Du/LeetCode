/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define M1  0x55555555
#define M2  0x33333333
#define M4  0x0f0f0f0f

int countBits (int n) { // n >= 0
  n = (n & M1) + ((n >> 1) & M1);
  n = (n & M2) + ((n >> 2) & M2);
  n = (n & M4) + ((n >> 4) & M4);
  n = n + (n >> 8);
  n = n + (n >> 16);
  return n & 0x1f;
}

static int cmp (const void *a, const void *b) {
  int m = *(int *)a, n = *(int *)b, d = m - n, db = countBits(m) - countBits(n);
  if (d == 0) {
    return 0;
  } else if (db == 0) {
    return d;
  }
  return db;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {

  qsort (arr, arrSize, sizeof (int), cmp);

  *returnSize = arrSize;
  return arr;
}