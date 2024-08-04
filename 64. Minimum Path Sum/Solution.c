int minPathSum_2(int** grid, int gridSize, int* gridColSize) {
  int i, j, m = gridSize, n = gridColSize[0], dp[m][n];

  dp[0][0] = grid[0][0];

  for (int i = 1; i < m; i++) {
    dp[i][0] = dp[i- 1][0] + grid[i][0];
  }

  for (int j = 1; j < n; j++) {
    dp[0][j] = dp[0][j - 1] + grid[0][j];
  }

  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      dp[i][j] = fmin (dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }

  return dp[m - 1][n - 1];
}


int minPathSum_1(int** grid, int gridSize, int* gridColSize) {
  int i, j, m = gridSize, n = gridColSize[0], dp[m][n];
  int downSum, rightSum, diagIdx, maxDiag = m + n - 2;

  dp[0][0] = grid[0][0];

  for (diagIdx = 1; diagIdx <= maxDiag; diagIdx++) {
    for (i = fmax (0, diagIdx - n + 1); i <= fmin (diagIdx, m - 1); i++) {
      j = diagIdx - i;
      downSum  = (i > 0) ? dp[i - 1][j] : INT_MAX;
      rightSum = (j > 0) ? dp[i][j - 1] : INT_MAX;
      dp[i][j] = fmin (downSum, rightSum) + grid[i][j];
    }
  }

  return dp[m - 1][n - 1];
}