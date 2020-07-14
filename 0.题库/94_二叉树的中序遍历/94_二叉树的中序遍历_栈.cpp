class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
	    vector<int> ret;
	    if (root == NULL) return ret;
	    
        stack<TreeNode*> s;
	    TreeNode* node = root;
        // 没有压入元素或者有未弹出的元素
	    while (node || !s.empty())  {
            // 压入左子树
		    while (node) {
			    s.push(node);
			    node = node->left;
		    }
            // 弹出栈顶元素
			node = s.top();
            s.pop();
			ret.push_back(node->val); // 记录中序遍历结果
            // 进入右子树
			node = node->right;
        }
	    return ret;
    }
};