/*************************************************************************
	> File Name: 337_打家劫舍III.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jul 2020 11:04:29 AM CST
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
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) return vector<int>(2, 0);
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        
        vector<int> ret(2, 0);
        ret[0] = max(l[0], l[1]) + max(r[0], r[1]);
        ret[1] = l[0] + r[0] + root->val;
        return ret;
    }

    int rob(TreeNode* root) {
        vector<int> ret = dfs(root);
        return max(ret[0], ret[1]);
    }
};
