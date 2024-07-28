int countTriples(int n) {
    int i, j, sum, val, cnt = 0, max = (n / sqrt (2)) + 1;

    for (i = 1; i <= max; i++) {
        for (j = i; j <= n; j++) {
            sum = i * i + j * j;
            val = (int) sqrt (sum + 1);
            if (val > n) {
                break;
            }
            if (val * val == sum) {
                cnt += (i == j) ? 1 : 2;
            }
        }
    }

    return cnt;
}

int countTriples(int n) {  // Faster than 100% solutions!!!
    int i, j, cnt = 0, max = (n / sqrt (2)) + 1;
    double val;

    for (i = 1; i <= max; i++) {  // i < max, if max = ceil (n / sqrt (2));
        for (j = i + 1; j <= n; j++) {
            val = sqrt (i * i + j * j);
            if (val > n) {
                break;
            } else if (val == (int) val) {
                cnt += 2;
            }
        }
    }

    return cnt;
}