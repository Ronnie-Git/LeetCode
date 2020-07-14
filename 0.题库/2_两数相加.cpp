struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l1) return l2;
    if (!l2) return l1;

    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));;
    node->next = l1;
    int temp = 0;
    while (l2 || temp) {
        int val = 0;
        if (l2) val = l2->val;
        if (!node->next) node->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        node->next->val = node->next->val + val + temp;
        temp = node->next->val / 10;
        node->next->val %= 10;
        node = node->next;
        if (l2) l2 = l2->next;
    }
    return l1;
}