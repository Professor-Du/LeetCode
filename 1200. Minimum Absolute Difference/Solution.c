/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int cmp (const void *a, const void *b) {
   return *((int *)a) - *((int *)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
  int i, diff, cnt = 0, minDiff = INT_MAX, **r = malloc (sizeof (int *) * arrSize);

  for (i = 0; i < arrSize; i++) {
    r[i] = malloc (sizeof (int) * 2);
  }
  // (*r)[2];
  // r = malloc (sizeof (int) * arrSize * 2);

  qsort (arr, arrSize, sizeof (int), cmp);

  for (i = 0; i < arrSize - 1; i++) {
    diff = arr[i + 1] - arr[i];
    if (diff > minDiff) {
      continue;
    }

    if (diff < minDiff) {
      cnt = 0;
      minDiff = diff;
    }

    r[cnt][0] = arr[i];
    r[cnt][1] = arr[i + 1];
    cnt++;
  }

  *returnSize = cnt;
  *returnColumnSizes = malloc (sizeof (int) * cnt);

  for (i = 0; i < cnt; i++) {
    (*returnColumnSizes)[i] = 2;
  }
  return r;
}