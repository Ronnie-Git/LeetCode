/*************************************************************************
	> File Name: ZJ68II_二叉树的最近公共祖先.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 02:38:24 PM CST
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
        if (!root || p->val == root->val || q->val == root->val) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (!l) return r;
        if (!r) return l;
        return root;
    }
};
