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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode newhead;
        newhead.next = head;
    	ListNode *p = &newhead;
        while (p && p->next) {
        	if (p->next->val == val) {
        		ListNode *del = p->next;
        		p->next = del->next;
        		//delete del;
        		break;
        	}
        	p = p->next;
        }
        return newhead.next;
    }
};