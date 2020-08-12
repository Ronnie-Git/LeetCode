/*************************************************************************
	> File Name: 02.02_返回倒数第k个节点.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2020 09:33:43 AM CST
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
    int kthToLast(ListNode* head, int k) {
        ListNode *q = head, *p = head;
        while (k --) q = q->next;
        while (q) p = p->next, q = q->next;
        return p->val;
    }
};
