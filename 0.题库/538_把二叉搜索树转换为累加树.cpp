/*************************************************************************
	> File Name: 538_把二叉搜索树转换为累加树.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Sep 2020 05:56:40 PM CST
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
    TreeNode* convertBST(TreeNode* root) {
        int num = 0;
        _convertBST(root, num);
        return root;
    }

    void _convertBST(TreeNode *root, int &num) {
        if (!root) return ;
        _convertBST(root->right, num);
        root->val += num;
        num = root->val;
        _convertBST(root->left, num);
        return ;
    }
};
