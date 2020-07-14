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
    vector<int> reversePrint(ListNode* head) {
    	vector<int> res;
    	if (head == NULL) return res;

    	ListNode *p = head;
    	while (p != NULL) {
    		res.push_back(p->val);
    		p = p->next;
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
};