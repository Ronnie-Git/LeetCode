/*************************************************************************
	> File Name: 04.12_求和路径.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Jul 2020 08:40:57 AM CST
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
    void g(TreeNode* r,int s,int &a) {
        if(!r) return;
        if(s==r->val) ++a;
        g(r->left,s-r->val,a);
        g(r->right,s-r->val,a);

        return;
    }
    void f(TreeNode* r,int s,int& a) {
        if(!r) return;
        g(r,s,a);
        f(r->left,s,a);
        f(r->right,s,a);

        return;
    }
    int pathSum(TreeNode* root, int sum) {
        int a=0;
        f(root,sum,a);
        return a;
    }
};
