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
	void dfs(vector<vector<int>> &res, vector<int> &temp, TreeNode *root, int sum) {
		if (!root) return ;
		sum -= root->val;
        temp.push_back(root->val);
		if (!sum && !root->left && !root->right) res.push_back(temp);
		dfs(res, temp, root->left, sum);
		dfs(res, temp, root->right, sum);
		temp.pop_back();
		return ;
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> res;
    	vector<int> temp;
    	dfs(res, temp, root, sum);
    	return res;
    }
};