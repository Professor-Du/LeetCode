static int cmp (const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int minRectanglesToCoverPoints(int** points, int pointsSize, int* pointsColSize, int w) {
    int i, cnt = 0, right = -1;
    qsort (points, pointsSize, sizeof (int) * pointsColSize[0], cmp);
    for (i = 0; i < pointsSize; i++) {
        if (points[i][0] > right) {
            right = points[i][0] + w;
            cnt++;
        }
    }

    return cnt;
}