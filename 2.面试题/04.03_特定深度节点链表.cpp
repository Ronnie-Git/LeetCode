/*************************************************************************
	> File Name: 04.03_特定深度节点链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Aug 2020 12:30:49 AM CST
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode *> res;
        queue<TreeNode *> q;
        if (tree == NULL) return res;
        q.push(tree);
        while (!q.empty()) {
            int len = q.size();
            ListNode *head = new ListNode(0);
            ListNode *p = head;
            for (int i = 0; i < len; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (i == 0) head->val = node->val;
                else {
                    ListNode *temp = new ListNode(node->val);
                    p->next = temp;
                    p = p->next;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(head);
        }
        return res;
    }
};
