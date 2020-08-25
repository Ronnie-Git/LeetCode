/*************************************************************************
	> File Name: 04.04_检查平衡性.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Aug 2020 12:20:01 AM CST
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
    int dep(TreeNode *root) {
        if (root == NULL) return 0;
        return max(dep(root->left), dep(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return abs(dep(root->left) - dep(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
