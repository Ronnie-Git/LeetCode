/*************************************************************************
	> File Name: 02.01_移除重复节点.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2020 09:54:41 PM CST
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> flags;
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head, *q = head->next;
        flags.insert(p->val);
        while (q) {
            if (flags.find(q->val) == flags.end()) {
                flags.insert(q->val);
                q = q->next;
                p = p->next;
            } else {
                ListNode *del = q;
                p->next = q->next;
                q = q->next;
                //delete del;
            }
        }
        return head;
    }
};
