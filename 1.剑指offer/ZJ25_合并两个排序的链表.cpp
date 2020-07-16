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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (!l1 || !l2) return !l1 ? l2 : l1;
    	ListNode newHead, *p = &newHead;
    	while (l1 && l2) {
    		if (l1->val > l2->val) {
    			p->next = l2;
    			l2 = l2->next;
    		} else {
    			p->next = l1;
    			l1 = l1->next;
    		}
    		p = p->next;
    	}
    	p->next = (l1 ? l1 : l2);
    	return newHead.next;
    }
};