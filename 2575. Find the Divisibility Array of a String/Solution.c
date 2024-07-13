/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divisibilityArray(char * word, int m, int* returnSize){
    long val = 0; 
    int n = strlen (word), *div = malloc (sizeof (int) * n);

    for (int i = 0; i < n; i++) {
        val = (val * 10 + word[i] - '0') % m;
        div[i] = (val == 0);
    }

    *returnSize = n;
    return div;
}