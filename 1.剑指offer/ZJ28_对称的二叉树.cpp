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
	bool check(TreeNode *l, TreeNode *r) {
		if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        return check(l->left, r->right) && check(l->right, r->left);
	}

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};