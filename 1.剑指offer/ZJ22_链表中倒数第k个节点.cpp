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
    ListNode* getKthFromEnd(ListNode* head, int k) {
    	if (!head) return head;
    	ListNode newHead;
    	newHead.next = head;
    	ListNode *p = &newHead, *q = head;
    	while (k-- && q) q = q->next; 
    	while (q) {
    		p = p->next;
    		q = q->next;
    	}
    	return p->next;
    }
};