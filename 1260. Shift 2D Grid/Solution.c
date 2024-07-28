

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
  int i, j, m = gridSize, n = gridColSize[0], tot = m * n, **buf = malloc (sizeof (int *) * m);

  *returnSize = m;
  *returnColumnSizes = malloc (sizeof (int) * m);
  for (i = 0; i < m; i++) {
    buf[i] = malloc (sizeof (int) * n);
    (*returnColumnSizes)[i] = n;
  }
  for (i = 0; i < tot; i++) {
    j = (i + k) % tot;
    buf[j/n][j%n] = grid[i/n][i%n];
  }

  return buf;
}