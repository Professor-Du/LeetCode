/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int i, j, *hash = calloc (1001, sizeof (int));
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsColSize[i]; j++) {
            hash[nums[i][j]]++;
        }
    }

    for (i = 0, j = 0; i < 1001; i++) {
        if (hash[i] == numsSize) {
            hash[j++] = i;
        }
    }

    *returnSize = j;
    return hash;
}