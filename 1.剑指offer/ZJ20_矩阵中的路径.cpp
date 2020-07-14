int dir[4][2] = {0, 1, -1, 0, 1, 0, 0, -1};
int vis[300][300] = {0};

bool dfs(char **arr, int n, int m, int x, int y, char *str, int len, int ind) {
	if (ind == len) return true;
	
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0], ty = y + dir[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        if (vis[tx][ty]) continue;
        if (arr[tx][ty] != str[ind]) continue;
        vis[tx][ty] = 1;
		if (dfs(arr, n, m, tx, ty, str, len, ind + 1)) return true;
		vis[tx][ty] = 0;
	}
	
	return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    memset(vis, 0, sizeof(vis));
	int m = *boardColSize, len = strlen(word);
	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] != word[0]) continue;
			vis[i][j] = 1;
			if (dfs(board, boardSize, m, i, j, word, len, 1)) return true;
            vis[i][j] = 0;
		}
	}
	return false;
}