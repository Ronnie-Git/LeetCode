/*************************************************************************
	> File Name: 958.二叉树的完全性检验.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Aug 2020 07:25:30 PM CST
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        if (root == NULL) return true;
        int flag = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left == NULL && temp->right) return false;
            if (flag && (temp->left || temp->right)) return false;
            if (temp->left == NULL || temp->right == NULL) flag = 1;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return true;
    }
};
