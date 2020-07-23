/*************************************************************************
	> File Name: ZJ36_二叉搜索树与双向链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jul 2020 11:26:19 AM CST
 ************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        _build(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void _build(Node *node) {
        if (!node) return ;
        _build(node->left);
        if (!pre) head = node;
        else pre->right = node;
        node->left = pre;
        pre = node;
        _build(node->right);

        return ;
    }
private :
    Node *pre, *head;
};
