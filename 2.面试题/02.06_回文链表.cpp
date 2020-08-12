/*************************************************************************
	> File Name: 02.06_回文链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2020 09:58:59 AM CST
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *p = head, *nhead = NULL, *q = NULL;
        int cnt = 0;
        while (p) {p = p->next; ++cnt;}
        
        int mid = cnt >> 1;
        p = head;
        while (mid--) {
            q = p->next;
            p->next = nhead;
            nhead = p;
            p = q;
        }
        
        if (cnt & 1) p = p->next;
        while (p) {
            if (p->val != nhead->val) return false;
            p = p->next;
            nhead = nhead->next;
        }
        return true;
    }
};
