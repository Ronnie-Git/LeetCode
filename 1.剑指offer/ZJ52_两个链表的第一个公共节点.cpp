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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return !headA ? headA : headB;
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = (p ? p->next : headB);
            q = (q ? q->next : headA); 
        }
        return p;
    }
};
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return !headA ? headA : headB;
        int lenA = 0, lenB = 0, i = 0;
        ListNode *p = headA, *q = headB;
        while (p || q) {
        	if (p) ++lenA, p = p->next;
        	if (q) ++lenB, q = q->next;
        }
        p = headA, q = headB;
        while (i++ < abs(lenA - lenB)) {
        	if (lenA > lenB) p = p->next;
        	else q = q->next;
        }
        while (p || q) {
        	if (p == q) return p;
        	p = p->next;
        	q = q->next;
        }
        return p;
    }
};
*/