/*************************************************************************
	> File Name: 61_旋转链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Sep 2020 04:18:53 PM CST
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        ListNode vir(-1); vir.next = head;
        ListNode *p = head, *q = &vir;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
            q = q->next;
        }
        q->next = head;
        k = len - k % len;

        p = head, q = &vir;
        while (k--) {
            p = p->next;
            q = q->next;
        }
        q->next = NULL;
        return p;
    }
};
