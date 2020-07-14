/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void _preorder(TreeNode *node, vector<int> &ret) {
        if (!node) return ;
        ret.push_back(node->val);
        _preorder(node->left, ret);
        _preorder(node->right, ret);
        return ;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        _preorder(root, ret);
        return ret;
    }
};