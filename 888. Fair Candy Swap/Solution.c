/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
  int i, j, delta = 0, alice = 0, bob = 0, *ans = malloc (sizeof (int) * 2);

  for (i = 0; i < aliceSizesSize; i++) {
    alice += aliceSizes[i];
  }

  for (j = 0; j < bobSizesSize; j++) {
    bob += bobSizes[j];
  }

  *returnSize = 2;
  delta = (alice + bob) / 2 - alice;
  for (i = 0; i < aliceSizesSize; i++) {
    for (j = 0; j < bobSizesSize; j++) {
      if (aliceSizes[i] + delta == bobSizes[j]) {
        ans[0] = aliceSizes[i];
        ans[1] = bobSizes[j];
        return ans;
      }
    }
  }

  return ans;
}