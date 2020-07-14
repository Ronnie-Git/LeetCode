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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size(), temp = 0;
            while (cnt--) {
                TreeNode *node = q.front(); q.pop();
                temp = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};