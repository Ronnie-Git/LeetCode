/*************************************************************************
	> File Name: 04.06_后继者.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Aug 2020 10:27:01 AM CST
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        cur = NULL, res = NULL;
        _inorder(root, p);
        return res;
    }
    
    void _inorder(TreeNode *root, TreeNode *p) {
        if (!root || res) return ;
        
        _inorder(root->left, p);
        if (cur && root && !res) {
            res = root;
            return ;
        }
        if (root == p) cur = root;
        
        _inorder(root->right, p);
        return ;
    }
private:
    TreeNode *cur;
    TreeNode *res;
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        if (p->val >= root->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode *l = inorderSuccessor(root->left, p);
            return l ? l : root;
        }
    }
};
