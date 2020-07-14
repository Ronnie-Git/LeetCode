class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;  
        if(root == NULL) return ret;            
        stack<TreeNode*> s;  
        s.push(root);  
        while(!s.empty()) {  
            TreeNode *n = s.top();
            s.pop();
            ret.push_back(n->val); // 记录后续遍历的过程值

            if(n->left)  s.push(n->left);  
            if(n->right) s.push(n->right);  
        }
        reverse(ret.begin(), ret.end()); // 将ret倒置获得后序遍历结果
        return ret;
    }
};