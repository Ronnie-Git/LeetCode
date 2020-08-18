/*************************************************************************
	> File Name: 109_有序链表转换二叉搜索树.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Aug 2020 10:51:19 PM CST
 ************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *p = head;
        int len = 0;
        while(p) {
            ++len;
            p = p->next;
        }
        return build(head, len);
    }

    TreeNode *build(ListNode *head, int len) {
        if (head == nullptr || len == 0) return nullptr;
        if (len == 1) return new TreeNode(head->val);
        int ind = 1, endind = len / 2;
        if (len & 1) ++endind;
        ListNode *p = head;
        while (p && ind < endind) {
            ++ind;
            p = p->next;
        }
        TreeNode *root = new TreeNode(p->val);
        root->left = build(head, endind - 1);
        root->right = build(p->next, len - endind);
        return root;
    }
};
