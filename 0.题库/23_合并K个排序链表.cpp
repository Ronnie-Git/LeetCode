/*************************************************************************
	> File Name: 23_合并K个排序链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2020 10:40:57 AM CST
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
    struct cmp {
        bool operator ()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        ListNode newHead(-1);
        ListNode *p = &newHead;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] == NULL) continue;
            q.push(lists[i]);
        }
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            if (node->next) q.push(node->next);
            p->next = node;
            node->next = NULL;
            p = p->next;
        }
        return newHead.next;
    }
};
