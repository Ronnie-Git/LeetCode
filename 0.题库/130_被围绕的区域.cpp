typedef struct UnionSet {
    int *fa;
    int *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->fa = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->fa[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->fa[x] != x) 
        return (u->fa[x] = find(u, u->fa[x]));
    return x;
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    u->fa[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u->size);
    free(u);
    return ;
}

int getInd(int i, int j, int m) {
    return i * m + j + 1;
}

void solve(char** board, int boardRowSize, int boardColSize) {
    UnionSet *u = init(boardRowSize * boardColSize + 5);
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] != 'O') continue;
            if ((i == 0 || i == boardRowSize - 1 || j == 0 || j == boardColSize - 1)) {
                merge(u, 0, getInd(i, j, boardColSize));
            }
            if (i - 1 >= 0 && board[i - 1][j] == 'O') {
                merge(u, getInd(i, j, boardColSize), getInd(i - 1, j, boardColSize));
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O') {
                merge(u, getInd(i, j, boardColSize), getInd(i, j - 1, boardColSize));
            }

        }
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] != 'O') continue;
            if (find(u, getInd(i, j, boardColSize)) != find(u, 0)) {
                board[i][j] = 'X';
            }
        }
    }
    clear(u);
    return ;
}


// 在外圈再画一层圈 都编号为0 确定边界上的点与0号的连通性