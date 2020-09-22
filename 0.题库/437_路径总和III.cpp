/*************************************************************************
	> File Name: 437_路径总和III.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Sep 2020 06:52:47 PM CST
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
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        dfs(root, 0, sum, ans, m);
        return ans;
    }

    void dfs(TreeNode *root, int num, int sum, int &ans, unordered_map<int, int> &m) {
        if (!root) return ;
        num += root->val;
        int temp = num - sum;
        if (m.find(temp) != m.end()) {
            ans += m[temp];
        }
        m[num] ++;
        dfs(root->left, num, sum, ans, m);
        dfs(root->right, num, sum, ans, m);
        m[num] --;
        return ;
    }
};
