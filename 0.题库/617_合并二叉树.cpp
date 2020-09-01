/*************************************************************************
	> File Name: 617_合并二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Aug 2020 11:46:44 PM CST
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        TreeNode *node = new TreeNode(0), *l1 = NULL, *r1 = NULL, *l2 = NULL, *r2 = NULL;
        if (t1) {
            node->val += t1->val;
            l1 = t1->left;
            r1 = t1->right;
        }
        if (t2) {
            node->val += t2->val;
            l2 = t2->left;
            r2 = t2->right;
        }
        node->left = mergeTrees(l1, l2);
        node->right = mergeTrees(r1, r2);
        return node;
    }
};
