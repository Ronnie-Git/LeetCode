class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> s;
        TreeNode *p = root, *r = nullptr;
        while(p || !s.empty()){
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if (p->right && p->right != r) { //考虑栈顶结点的右子树结点。存在且没被访问过，将右子树结点压入栈中
                p=p->right;
            } else {
                s.pop();
                result.push_back(p->val);
                r = p;
                p = nullptr;
                //p置空作用在于当原栈顶结点被访问并弹出后，下一层while是将当前栈顶结点的左子树入栈，当前栈顶结点的左子树已经被遍历过，		
			//因此会造成死循环，所以将p置空，直接考虑当前栈顶结点的右子树
            }
        }
        return result;
    }
};