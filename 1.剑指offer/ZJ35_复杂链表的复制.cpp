/*************************************************************************
	> File Name: ZJ35_复杂链表的复制.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jul 2020 10:50:47 AM CST
 ************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node *, Node *> m;
        Node virhead(0, NULL, NULL);
        
        Node *p = &virhead, *q = head;
        while (q) {
            p->next = new Node(q->val, NULL, NULL);
            m.insert(make_pair(q, p->next));
            q = q->next;
            p = p->next;
        }

        p = &virhead, q = head;
        while (q) {
            p->next->random = m[q->random];
            q = q->next;
            p = p->next;
        }

        return virhead.next;
    }
};
