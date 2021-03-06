bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int rom[9] = {0}, col[9] = {0}, gong[9] = {0};
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            int val = board[i][j] - '0';
            if (val + '0' == '.') continue;
            int ind = i / 3 * 3 + j / 3;
            if (rom[i] & (1 << val)) return false;
            if (col[j] & (1 << val)) return false;
            if (gong[ind] & (1 << val)) return false;
            rom[i] |= (1 << val);
            col[j] |= (1 << val);
            gong[ind] |= (1 << val);
        }
    }
    return true;
}