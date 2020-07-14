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
    void _dfs(TreeNode *node, int sum, vector<int> &path, vector<vector<int> > &res) {
        if (!node) return ;

        sum -= node->val; path.push_back(node->val);
        if (!node->left && !node->right) {
            if (sum == 0) res.push_back(path);
            path.pop_back();
            return ;
        }
        _dfs(node->left, sum, path, res);
        _dfs(node->right, sum, path, res);
        path.pop_back();
        return ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        _dfs(root, sum, path, res);
        return res;
    }
};