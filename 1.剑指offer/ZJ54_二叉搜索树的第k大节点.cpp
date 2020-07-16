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
	bool inorder(TreeNode *root, int &k, int &res) {
		if (!root) return false;
        if (inorder(root->right, k, res)) return true;
		if (--k == 0) {
			res = root->val;
			return true;
		}
		if (inorder(root->left, k, res)) return true;
		return false;
	}

    int kthLargest(TreeNode* root, int k) {
    	int res = 0;
       	inorder(root, k, res);
       	return res;
    }
};