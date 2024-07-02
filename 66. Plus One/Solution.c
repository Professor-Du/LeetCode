/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i, carry, *s = malloc(sizeof(int) * (digitsSize + 1));

    for (i = digitsSize - 1, carry = 1; i >= 0; i--) {
        digits[i] += carry;
        s[i + 1] = digits[i] % 10;
        carry = digits[i] / 10;
    }

    if (carry != 0) {
        *returnSize = digitsSize + 1;
        s[0] = carry;
        return s;
    } else {
        *returnSize = digitsSize;
        return s + 1;
    }
}