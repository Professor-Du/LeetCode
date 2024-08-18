const int INF = (1 << 20) - 1;

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int dfs(int i, int j, int cur, const int *nums, int numsSize,  const int *andValues, int andValuesSize, HashItem **memo) {
    int n = numsSize, m = andValuesSize, key = i * m + j;
    if (i == n && j == m) {
        return 0;
    }
    if (i == n || j == m) {
        return INF;
    }
    if (hashFindItem(&memo[key], cur)) {
        return hashGetItem(&memo[key], cur, 0);
    }

    cur &= nums[i];
    if ((cur & andValues[j]) < andValues[j]) {
        return INF;
    }
    int res = dfs(i + 1, j, cur, nums, numsSize, andValues, andValuesSize, memo);
    if (cur == andValues[j]) {
        res = fmin(res, dfs(i + 1, j + 1, INF, nums, numsSize, andValues, andValuesSize, memo) + nums[i]);
    }
    hashAddItem(&memo[key], cur, res);
    return res;
}

int minimumValueSum(int* nums, int numsSize, int* andValues, int andValuesSize) {
    int n = numsSize, m = andValuesSize;
    HashItem *memo[m * n];
    for (int i = 0; i < m * n; i++) {
        memo[i] = NULL;
    }
    int res = dfs(0, 0, INF, nums, numsSize, andValues, andValuesSize, memo);
    for (int i = 0; i < m * n; i++) {
        hashFree(&memo[i]);
    }
    return res < INF ? res : -1;
}