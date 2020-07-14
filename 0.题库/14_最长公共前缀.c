#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    int cnt;
    struct Node *next[BASE_CNT];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    p->cnt = 0;
    return p;
}

void insert(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        p = p->next[str[i] - BASE];
        p->cnt++;
    }
    p->flag = 1;
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

void find(Node *root, char *ans, int ind, int strsSize) {
    Node *p = root;
    int k = -1;
    for (int i = 0; i < BASE_CNT; i++) {
        if (p->next[i] == NULL) continue;
        k = i;
        break;
    }
    if (k == -1) return ;
    if (p->next[k]->cnt < strsSize) return ; 
    ans[ind] = k + BASE;
    
    find(p->next[k], ans, ind + 1, strsSize);
    return ;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    Node *root = getNewNode();
    int k = 0;
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) == 0) k++;
        insert(root, strs[i]);
    }
    char *ans = calloc(sizeof(char), 10000);
    if (strsSize > 1 && k) return ans;
    find(root, ans, 0, strsSize);
    clear(root);
    return ans;
}