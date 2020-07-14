class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
	    if (root == NULL) return ret;
	    stack<TreeNode*> s;
	    s.push(root);
	    while (!s.empty()) {
		    TreeNode* node = s.top();
            s.pop();
		    ret.push_back(node->val); // 记录先序遍历结果
		    if (node->right) s.push(node->right);
		    if (node->left) s.push(node->left);
	    }
        return ret;
    }
};