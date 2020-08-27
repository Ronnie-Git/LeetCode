/*************************************************************************
	> File Name: 04.05_合法二叉搜索树.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Aug 2020 08:54:23 AM CST
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
    bool isValidBST(TreeNode* root) {
       if (!root) return true;
       stack<TreeNode *> s;
       TreeNode *node = root, *pre = NULL;
       while (node || !s.empty()) {
           while (node) {
               s.push(node);
               node = node->left;
           }
           node = s.top();
           s.pop();
           if (pre == NULL) pre = node;
           else if (pre->val >= node->val) return false;
           else pre = node;
           node = node->right;
       }
       return true;
    }
};
