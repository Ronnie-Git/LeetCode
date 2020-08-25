/*************************************************************************
	> File Name: 02.08_环路检测.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Aug 2020 07:56:01 AM CST
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
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *p = head, *q = head;
        do {
            p = p->next;
            q = q->next;
            if (q) q = q->next;
        } while (p && q && p != q);
        if (!p || !q) return NULL;
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
