class Solution {
public:
        void _postorder(TreeNode *node, vector<int> &ret) {
        if (!node) return ;
        _postorder(node->left, ret);
        _postorder(node->right, ret);
        ret.push_back(node->val);
        return ;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        _postorder(root, ret);
        return ret;
    }
};