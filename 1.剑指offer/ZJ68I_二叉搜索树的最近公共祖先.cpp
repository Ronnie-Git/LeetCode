/*************************************************************************
	> File Name: ZJ68I_二叉搜索树的最近公共祖先.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 02:39:36 PM CST
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val, qval = q->val;
        while (root) {
            if (pval < root->val && qval < root->val) root = root->left;
            else if (pval > root->val && qval > root->val) root = root->right;
            else return root;
        }
        return root;
    }
};
