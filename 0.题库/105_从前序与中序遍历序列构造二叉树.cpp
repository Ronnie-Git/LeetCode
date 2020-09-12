/*************************************************************************
	> File Name: 105_从前序与中序遍历序列构造二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Sep 2020 08:55:54 PM CST
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* _buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (pe < ps || ie < is) return NULL;
        TreeNode *node = new TreeNode(preorder[ps]);
        int pimd, imid = is;
        while (imid <= ie && inorder[imid] != preorder[ps]) ++imid;
        pimd = ps + (imid - is);
        node->left = _buildTree(preorder, ps + 1, pimd, inorder, is, imid - 1);
        node->right = _buildTree(preorder, pimd + 1, pe, inorder, imid + 1, ie);
        return node;
    }
};
