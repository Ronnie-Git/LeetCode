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
    TreeNode* mirrorTree(TreeNode* root) {
    	if (!root) return root;
    	TreeNode *l = mirrorTree(root->left);
    	TreeNode *r = mirrorTree(root->right);
    	root->left = r;
    	root->right = l;
    	return root;
    }
};