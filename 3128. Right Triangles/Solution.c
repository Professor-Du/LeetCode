long long numberOfRightTriangles(int** grid, int gridSize, int* gridColSize) {
    long long sum = 0;
    int i, j, m = gridSize, n = gridColSize[0], *rowCnt = calloc (m, sizeof (int)), *colCnt = calloc (n, sizeof (int));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                rowCnt[i]++;
                colCnt[j]++;
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                sum += (long long) ((rowCnt[i] - 1) * (colCnt[j] - 1));
            }
        }
    }

    return sum;
}

long long numberOfRightTriangles_better(int** grid, int gridSize, int* gridColSize) {
    long long sum = 0;
    int i, j, m = gridSize, n = gridColSize[0], *rowCnt = calloc (m, sizeof (int)), *colCnt = calloc (n, sizeof (int));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
             rowCnt[i] += grid[i][j];
             colCnt[j] += grid[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                sum += (long long) ((rowCnt[i] - 1) * (colCnt[j] - 1));
            }
        }
    }

    return sum;
}