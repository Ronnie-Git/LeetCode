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
	int maxDepth(TreeNode* root) {
    	return !root ? 0 : (max(maxDepth(root->left), maxDepth(root->right)) + 1);
    }
    bool isBalanced(TreeNode* root) {
    	return !root ? true : (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};