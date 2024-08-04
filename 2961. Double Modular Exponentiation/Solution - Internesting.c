/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define IDX_A  0
#define IDX_B  1
#define IDX_C  2
#define IDX_M  3

int helper (int base, int power, int mod) {  // 1 <= base, power, mod <= 10^3
  int val = 1;
  base = base % mod;
  while (power > 0) {
    val = val % mod;
    val = val * base;
    power--;
  }

  return val % mod;
}

int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize) {
  int cnt = 0, *arr = malloc (sizeof (int) * variablesSize);
  for (int i = 0; i < variablesSize; i++) {
    if (variables[i][IDX_M] <= target) {
        continue;
    }
    if (helper (helper (variables[i][IDX_A], variables[i][IDX_B], 10), variables[i][IDX_C], variables[i][IDX_M]) == target) {
        arr[cnt++] = i;
    }
  }

  *returnSize = cnt;
  return arr;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define IDX_A  0
#define IDX_B  1
#define IDX_C  2
#define IDX_M  3

int myPow (int base, int power, int mod) {
    base %= mod;
    if (power == 1) {
        return base;
    }

    int x = (myPow (base, power / 2, mod) * myPow (base, power / 2, mod)) % mod;  // Internesting

    if (power & 1) {  // Internesting
        return (x * base) % mod;
    } else {
        return x;
    }
}

int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize) {
  int cnt = 0, *arr = malloc (sizeof (int) * variablesSize);
  for (int i = 0; i < variablesSize; i++) {
    if (variables[i][IDX_M] <= target) {
        continue;
    }
    if (myPow (myPow (variables[i][IDX_A], variables[i][IDX_B], 10), variables[i][IDX_C], variables[i][IDX_M]) == target) {
        arr[cnt++] = i;
    }
  }

  *returnSize = cnt;
  return arr;
}