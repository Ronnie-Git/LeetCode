int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int left_Depth = maxDepth(root->left);
    int right_Depth = maxDepth(root->right);
    return (left_Depth > right_Depth ? left_Depth : right_Depth) + 1;
}