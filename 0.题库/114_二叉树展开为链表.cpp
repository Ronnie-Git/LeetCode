/*************************************************************************
	> File Name: 114_二叉树展开为链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Sep 2020 06:07:39 PM CST
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return ;
        pre = nullptr;
        helper(root);
        return ;
    }

    void helper(TreeNode *root) {
        if (!root) return ;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        if (pre != nullptr) {
            pre->right = root;
            pre->left = nullptr;
        }
        pre = root;

        helper(l);
        helper(r);
    }

private:
    TreeNode *pre;
};
