/*************************************************************************
	> File Name: 543_二叉树的直径.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Sep 2020 06:11:02 PM CST
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode *root, int &ans) {
        if (!root) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};
