char* reverseStr(char* s, int k) {
    char temp;
    int start, i, j, n = strlen(s);

    for (start = 0; start < n; start += 2 * k) {
        for (i = start, j = fmin (start + k, n) - 1; i < j; i++, j--) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    return s;
}