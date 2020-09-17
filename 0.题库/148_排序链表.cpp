/*************************************************************************
	> File Name: 148_排序链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 15 Sep 2020 07:03:37 PM CST
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
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        return merge_sort(head);    
    }

private:
    ListNode *merge_sort(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *mid = findMid(head);
        ListNode *l = merge_sort(head);
        ListNode *r = merge_sort(mid);
        
        ListNode vir(-1), *p = &vir;
        
        while (l || r) {
            if (!l || (r && l->val > r->val)) {
                p->next = r;
                r = r->next;
            } else {
                p->next = l;
                l = l->next;
            }
            p = p->next;
        }
        
        return vir.next;
    }

    ListNode *findMid(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode vir(-1);
        vir.next = head;
        ListNode *p = &vir, *q = head;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
        }
        
        ListNode *retHead = p->next;
        p->next = NULL;
        return retHead;
    }
};
