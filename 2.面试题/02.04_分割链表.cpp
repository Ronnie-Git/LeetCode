/*************************************************************************
	> File Name: 02.04_分割链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Aug 2020 10:52:00 AM CST
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head; 
        ListNode *p = head, *q = head;
        while (p) {
            if (p->val < x) {
                int temp = q->val;
                q->val = p->val;
                p->val = temp;
                q = q->next;
            }
            p = p->next;
        }
        return head;
    }
};
