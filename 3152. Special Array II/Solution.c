/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial_better(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  bool *ans = malloc (sizeof (bool) * queriesSize);
  int i, cache[numsSize];

  cache[0] = 0;
  for (i = 1; i < numsSize; i++) {
    cache[i] = cache[i - 1] + ((nums[i] & 1) == (nums[i - 1] & 1));
  }

  for (i = 0; i < queriesSize; i++) {
    ans[i] = cache[queries[i][1]] == cache[queries[i][0]];
  }

  *returnSize = queriesSize;
  return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  bool *ans = malloc (sizeof (bool) * queriesSize);
  int i, cache[numsSize];

  cache[0] = 0;
  for (i = 1; i < numsSize; i++) {
    cache[i] = cache[i - 1] + (((nums[i] ^ nums[i - 1]) & 1) ? 1 : -1);
  }

  for (i = 0; i < queriesSize; i++) {
    ans[i] = (queries[i][1] - queries[i][0]) == (cache[queries[i][1]] - cache[queries[i][0]]);
  }

  *returnSize = queriesSize;
  return ans;
}