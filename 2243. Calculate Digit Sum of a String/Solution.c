char* digitSum(char* s, int k) {  // Faster than 100% solutions!!!
    int len = strlen (s);
    if (k >= len) {
        return s;
    }

    int i, m, sum;
    char c, *r = s;
    for (i = 0, m = k, sum = 0; i < len; i++) {
        c = s[i];
        if (i == m) {
            sprintf (r, "%d", sum);
            r += strlen (r);
            m += k;
            sum = 0;
        }
        sum += c - '0';
    }

    sprintf (r, "%d", sum);

    return digitSum(s, k);
}