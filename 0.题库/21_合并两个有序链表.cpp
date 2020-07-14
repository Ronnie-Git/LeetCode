struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL || l2 == NULL) return l1 ? l1 : l2;
    struct ListNode *root, *p1 = l1, *p2 = l2;
    if (l1->val < l2->val) {
        root = p1;
        p1 = p1->next;
    } else {
        root = p2;
        p2 = p2->next;
    }
    struct ListNode *p = root;
    while (p1 || p2) {
        if (p2 == NULL || (p1 && p1->val <= p2->val)) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    return root;
}