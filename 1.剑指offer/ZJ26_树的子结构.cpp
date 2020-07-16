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
	bool check(TreeNode* a, TreeNode *b) {
		if (!b) return true;
		if (!a || a->val != b->val) return false;
		return check(a->left, b->left) && check(a->right, b->right);
	}

    bool isSubStructure(TreeNode* A, TreeNode* B) {
    	return (A && B) && (check(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
};