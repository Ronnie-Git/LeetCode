/*************************************************************************
	> File Name: 02.05_链表求和.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2020 09:47:06 AM CST
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *p = &head;
        int temp = 0;
        while (l1 || l2 || temp) {
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(temp % 10);
            temp /= 10;
            p = p->next;
        }
        return head.next;
    }
};
