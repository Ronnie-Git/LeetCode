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
	unordered_map<int, int> mino;

    TreeNode* _build(vector<int>& pre, int pl, int pr, vector<int>& ino, int il, int ir) {
        if (pl > pr || il > ir) return NULL;
        int imid = mino[pre[pl]], pmid = pl + imid - il;

        TreeNode *node = new TreeNode;
        node->val = pre[pl];
        node->left = _build(pre, pl + 1, pmid, ino, il, imid - 1);
        node->right = _build(pre, pmid + 1, pr, ino, imid + 1, ir);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() <= 0 || inorder.size() <= 0) return NULL;
        for (int i = 0; i < inorder.size(); ++i) mino[inorder[i]] = i;
        return _build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};