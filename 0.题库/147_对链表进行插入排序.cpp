/*************************************************************************
	> File Name: 147_对链表进行插入排序.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Aug 2020 10:01:55 PM CST
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode vir(-1);
        ListNode *p = head;
        while (p) {
            ListNode *i = &vir, *temp = p->next;
            while (i->next) {
                if (p->val > i->next->val) i = i->next;
                else break;
            }
            p->next = i->next;
            i->next = p;
            
            p = temp;
        }
        return vir.next;
    }
};
