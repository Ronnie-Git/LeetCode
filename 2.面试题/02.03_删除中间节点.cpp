/*************************************************************************
	> File Name: 02.03_删除中间节点.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Aug 2020 10:08:12 AM CST
 ************************************************************************/

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
    void deleteNode(ListNode* node) {
        ListNode *del = node->next;
        node->val = del->val;
        node->next = del->next;
        delete del;
        return ;
    }
};
