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
    ListNode* reverseList(ListNode* head) {
    	if (!head) return head;
    	ListNode *p = head, *q = NULL, *temp = NULL;
    	while (p) {
    		temp = p->next;
    		p->next = q;
    		q = p;
    		p = temp;
    	}
    	return q;
    }
};