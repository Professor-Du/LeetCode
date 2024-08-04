typedef struct {
    int xCnt;
    int yCnt;
} COUNT_STRUCT;

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int i, j, num = 0, m =gridSize, n = gridColSize[0];
    COUNT_STRUCT gCnt[m][n];

    gCnt[0][0].xCnt = 0; gCnt[0][0].yCnt = 0;
    switch (grid[0][0]) {
        case 'X': gCnt[0][0].xCnt++; break;
        case 'Y': gCnt[0][0].yCnt++; break;
    }

    for (i = 1; i < n; i++) {
        gCnt[0][i].xCnt = gCnt[0][i - 1].xCnt;
        gCnt[0][i].yCnt = gCnt[0][i - 1].yCnt;
        switch (grid[0][i]) {
            case 'X': gCnt[0][i].xCnt++; break;
            case 'Y': gCnt[0][i].yCnt++; break;
        }
        if (gCnt[0][i].xCnt == gCnt[0][i].yCnt && gCnt[0][i].xCnt != 0) {
            num++;
        }
    }

    for (i = 1; i < m; i++) {
        gCnt[i][0].xCnt = gCnt[i - 1][0].xCnt;
        gCnt[i][0].yCnt = gCnt[i - 1][0].yCnt;
        switch (grid[i][0]) {
            case 'X': gCnt[i][0].xCnt++; break;
            case 'Y': gCnt[i][0].yCnt++; break;
        }
        if (gCnt[i][0].xCnt == gCnt[i][0].yCnt && gCnt[i][0].xCnt != 0) {
            num++;
        }
    }

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            gCnt[i][j].xCnt = gCnt[i - 1][j].xCnt + gCnt[i][j - 1].xCnt - gCnt[i - 1][j - 1].xCnt;
            gCnt[i][j].yCnt = gCnt[i - 1][j].yCnt + gCnt[i][j - 1].yCnt - gCnt[i - 1][j - 1].yCnt;
            switch (grid[i][j]) {
                case 'X': gCnt[i][j].xCnt++; break;
                case 'Y': gCnt[i][j].yCnt++; break;
            }
            if (gCnt[i][j].xCnt == gCnt[i][j].yCnt && gCnt[i][j].xCnt != 0) {
                num++;
            }
        }
    }

    return num;
}