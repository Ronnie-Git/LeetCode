/*************************************************************************
	> File Name: 404_左叶子之和.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Sep 2020 02:02:43 PM CST
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int l = 0;
        if (root->left && !root->left->left && !root->left->right)  {
            l = root->left->val;
        } else {
            l = sumOfLeftLeaves(root->left);
        }
        int r = sumOfLeftLeaves(root->right);
        return l + r;
    }
};
