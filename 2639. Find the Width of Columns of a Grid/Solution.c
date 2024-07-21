/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int getWidth (int val) {
//     if (val == 0) {
//         return 1;
//     } else if (val < 0) {
//         return (int) log10(-val) + 2;
//     } else {
//         return (int) log10(val) + 1;
//     }
// }

int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    *returnSize = gridColSize[0];

    int val, width, *w = malloc (sizeof (int) * (*returnSize));
    for (int j = 0; j < *returnSize; j++) {
        w[j] = 0;
        for (int i = 0; i < gridSize; i++) {
            val = grid[i][j];
            if (val == 0) {
                width = 1;
            } else if (val < 0) {
                width = (int) log10(-val) + 2;
            } else {
                width = (int) log10(val) + 1;
            }
            w[j] = fmax (w[j], width);
        }
    }

    return w;
}