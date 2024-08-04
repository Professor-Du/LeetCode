/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int i, cnt = 0, *arr = malloc (sizeof (int) * numsSize);

    qsort (nums, numsSize, sizeof (int), cmp);
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            arr[cnt++] = i;
        }
    }

    *returnSize = cnt;

    return arr;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices_better(int* nums, int numsSize, int target, int* returnSize) {  // LeetCode official solution #2
    int i, idx = 0, cnt = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            cnt++;
        } else if (nums[i] < target) {
            idx++;
        }
    }

    int *arr = malloc (sizeof (int) * cnt);
    for (i = 0; i < cnt; i++) {
        arr[i] = idx + i;
    }

    *returnSize = cnt;
    return arr;
}