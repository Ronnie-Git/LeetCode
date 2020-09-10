/*************************************************************************
	> File Name: 124_二叉树中的最大路径和.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Sep 2020 12:49:08 PM CST
 ************************************************************************/

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
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);

        int temp = root->val + l + r;
        res = max(res, temp);
        return root->val + max(l, r);
    }
private:
    int res;
};
