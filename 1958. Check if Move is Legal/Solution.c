bool check (char** board, int xSize, int ySize, int x, int y, char color, int dx, int dy) {
    int step = 1;
    do {
        x += dx; y +=dy; step++;
        if (x < 0 || x >= xSize || y < 0 || y >= ySize) {
            return false;
        } else if (board[x][y] == '.') {
            return false;
        }
    } while (board[x][y] != color);
    return step >= 3;
}

bool checkMove(char** board, int boardSize, int* boardColSize, int rMove, int cMove, char color) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (check (board, boardSize, boardColSize[0], rMove, cMove, color, dx, dy)) {
                return true;
            }
        }
    }
    return false;
}