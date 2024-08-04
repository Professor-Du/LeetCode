/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int mRowCenter, mColCenter;

static int cmp (const void *a, const void *b) {
    int d1 = abs((*(int **)a)[0] - mRowCenter) + abs((*(int **)a)[1] - mColCenter);
    int d2 = abs((*(int **)b)[0] - mRowCenter) + abs((*(int **)b)[1] - mColCenter);
    return d1 - d2;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    *returnSize = rows * cols;
    *returnColumnSizes = malloc (sizeof (int) * (*returnSize));

    mRowCenter = rCenter;
    mColCenter = cCenter;

    int i, cellSize = sizeof (int) * 2, **cells = malloc (sizeof (int *) * (*returnSize));

    for (i = 0; i < *returnSize; i++) {
        cells[i] = malloc (cellSize);
        (*returnColumnSizes)[i] = 2;
        cells[i][0] = i / cols;
        cells[i][1] = i % cols;
    }

    qsort (cells, *returnSize, cellSize, cmp);

    return cells;
}