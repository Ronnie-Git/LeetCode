/*************************************************************************
	> File Name: 142_环形链表II.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 07:04:18 PM CST
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) break; 
        }

        if (p != q) return NULL;
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};
