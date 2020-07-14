/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define max 1000
void dfs(struct TreeNode *root,char *temp,int length, char **p,int* cnt){
    if(root == NULL) return;
    int tem = root->val,i = 0;
    char ch[20];
    if(tem < 0) temp[length++] = '-',tem = -tem;
    while(tem){
        ch[i++]= (tem %10 + '0');
        tem /= 10;
    }
    ch[i] = 0;
    for(int i = strlen(ch) - 1; i >= 0; i--){
        temp[length++] = ch[i];
    }
    
    
    if(root->left == NULL && root->right ==NULL){
        temp[length]= 0;
        p[(*cnt)] = (char *)malloc(sizeof(char) *(strlen(temp) + 1));
        strcpy(p[(*cnt)++],temp);
        return ;
    }
    
    temp[length++] = '-';
    temp[length++] = '>';
    dfs(root->left,temp,length,p,cnt);
    dfs(root->right,temp,length,p,cnt);
    return ;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int cnt = 0;
    char *temp = (char *)malloc(sizeof(char) * max);
    char **p = (char **)malloc(sizeof(char *)*max);
    dfs(root,temp,0,p,&cnt);
    *returnSize = cnt;
    return p;
}