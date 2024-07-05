/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int row, col, colMax, **answer = malloc (sizeof (int *) * matrixSize);

    for (row = 0; row < matrixSize; row++) {
        answer[row] = malloc (sizeof (int) * matrixColSize[0]);
    }

    for (col = 0; col < matrixColSize[0]; col++) {
        for (row = 0, colMax = -1; row < matrixSize; row++) {
            colMax = fmax (colMax, matrix[row][col]);
        }
        for (row = 0; row < matrixSize; row++) {
            answer[row][col] = (matrix[row][col] == -1) ? colMax : matrix[row][col];
        }
    }


    *returnSize = matrixSize;
    *returnColumnSizes = malloc (sizeof (int) * matrixSize);
    memcpy(*returnColumnSizes, matrixColSize, sizeof (int) * matrixSize);

    return answer;
}