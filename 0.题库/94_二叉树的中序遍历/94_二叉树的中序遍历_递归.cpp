class Solution {
public:
    void _inorder(TreeNode *node, vector<int> &res) {
        if (node == NULL) return ;
        _inorder(node->left, res);
        res.push_back(node->val);
        _inorder(node->right, res);
        return ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        _inorder(root, res);
        return res;
    }
};