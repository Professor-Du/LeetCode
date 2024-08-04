int integerBreak(int n) {
    int i, j, maxVal, dp[n + 1];

    dp[0] = dp[1] = 0;

    for (i = 2; i <= n; i++) {
        for (j = 1, maxVal = 0; j < i; j++) {
            maxVal = fmax (maxVal, fmax (j * (i - j), j * dp[i - j]));  // Internesting
        }
        dp[i] = maxVal;
    }

    return dp[n];
}