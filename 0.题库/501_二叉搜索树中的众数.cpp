/*************************************************************************
	> File Name: 501_二叉搜索树中的众数.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Sep 2020 01:43:34 PM CST
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> res;
        dfs(root, m);

        int cnt = 0;
        for (auto x : m) {
            cnt = max(cnt, x.second);
        }
        for (auto x : m) {
            if (x.second == cnt) res.push_back(x.first);
        }
        return res;
    }

    void dfs(TreeNode *root, unordered_map<int, int> &m) {
        if (!root) return ;
        m[root->val] ++;
        dfs(root->left, m);
        dfs(root->right, m);
        return ;
    }
};
