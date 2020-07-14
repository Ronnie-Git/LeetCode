class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> Tree;
        vector<int> ret;
        while (!Tree.empty() || root != nullptr) {
            while (root != nullptr) {
                ret.push_back(root->val);
                Tree.push(root);
                root = root->left;
            }
            root = Tree.top();
            Tree.pop();
            root = root->right;
        }
       
        return ret;
    }
};