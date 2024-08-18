int projectionArea(int** grid, int gridSize, int* gridColSize) {
  int i, j, n = gridSize, sum = 0, *maxX = calloc (n, sizeof (int)), *maxY = calloc (n, sizeof (int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (grid[i][j] != 0) {
        maxX[i] = fmax (maxX[i], grid[i][j]);
        maxY[j] = fmax (maxY[j], grid[i][j]);
        sum++;
      }
    }
  }

  for (i = 0; i < n; i++) {
    sum += maxX[i] + maxY[i];
  }
  return sum;
}