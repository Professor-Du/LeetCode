int diagonalSum(int** mat, int matSize, int* matColSize) {
  int i, sum = 0;

  for (i = 0; i < matSize; i++) {
    sum += mat[i][i] + mat[i][matSize - i - 1];
  }

  if (matSize & 1) {
    i = matSize / 2;
    sum -= mat[i][i];
  }

  return sum;
}