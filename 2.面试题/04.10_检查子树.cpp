/*************************************************************************
	> File Name: 04.10_检查子树.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Aug 2020 08:54:25 PM CST
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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t2) return true;
        if (!t1) return false;
        if (t1->val == t2->val && check_same(t1, t2)) return true;
        if (checkSubTree(t1->left, t2)) return true;
        if (checkSubTree(t1->right, t2)) return true;
        return false;
    }

    bool check_same(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return check_same(t1->left, t2->left) && check_same(t1->right, t2->right);
    }
};
