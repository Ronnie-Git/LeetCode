/*************************************************************************
	> File Name: 637_二叉树的层平均值.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Sep 2020 01:13:23 PM CST
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            double num = 0.0;
            for (int i = 0; i < len; ++i) {
                TreeNode *temp = q.front();
                q.pop();
                num += temp->val;
                if (temp->left) q.push(temp->left); 
                if (temp->right) q.push(temp->right); 
            }
            res.push_back(num / len);
        }
        return res;
    }
};
