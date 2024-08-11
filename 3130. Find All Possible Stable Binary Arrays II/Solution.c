int numberOfStableArrays(int zero, int one, int limit) {
    int i, j, dp[zero + 1][one + 1][2];

    memset (dp, 0, sizeof (dp));

    for (i = 1; i <= fmin (zero, limit); i++) {
      dp[i][0][0] = 1;
    }

    for (j = 1; j <= fmin (one, limit); j++) {
      dp[0][j][1] = 1;
    }

    for (i = 1; i <= zero; i++) {
      for (j = 1; j <= one; j++) {
        dp[i][j][0] = ((long long) dp[i - 1][j][0] + dp[i - 1][j][1] + ((i > limit) ? 1000000007 - dp[i - 1 - limit][j][1] : 0)) % 1000000007;
        dp[i][j][1] = ((long long) dp[i][j - 1][0] + dp[i][j - 1][1] + ((j > limit) ? 1000000007 - dp[i][j - 1 - limit][0] : 0)) % 1000000007;
      }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % 1000000007;
}