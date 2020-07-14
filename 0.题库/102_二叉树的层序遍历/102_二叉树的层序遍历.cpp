class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            ret.push_back(vector<int>() );
            for (int i = 1; i <= count; ++i) { // 遍历当前层所有结点，并将其孩子结点入队
                TreeNode* node = q.front();
                q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};