int maxScore(int** grid, int gridSize, int* gridColSize) {
  int i, j, temp, maxScore = INT_MIN, m = gridSize, n = gridColSize[0], dp[m][n];

  dp[0][0] = grid[0][0];
  for (i = 1; i < n; i++) {
    dp[0][i] = fmin (dp[0][i - 1], grid[0][i]);
    maxScore = fmax (maxScore, grid[0][i] - dp[0][i - 1]);
  }

  for (i = 1; i < m; i++) {
    dp[i][0] = fmin (dp[i - 1][0], grid[i][0]);
    maxScore = fmax (maxScore, grid[i][0] - dp[i - 1][0]);
  }

  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      temp = fmin (dp[i][j - 1], dp[i - 1][j]);
      dp[i][j] = fmin (grid[i][j], temp);
      maxScore = fmax (maxScore, grid[i][j] - temp);
    }
  }

  return maxScore;
}