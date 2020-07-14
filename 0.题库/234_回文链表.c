/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int num[100005] = {0};
    if (head == NULL) return true;
    if (head->next == NULL) return true;
    int i = 0;
    struct ListNode *c = head;
    while (c != NULL) {
        c = c->next;
        i++;
    }
    int x = 0, y = 0;
    if (i % 2 == 0) {
        x = i / 2;
        y = x + 1;
    } else {
        x = i / 2;
        y = x + 2;
    }
    int j = 0;
    c = head;
    while (j < x) {
        num[j++] = c->val;
        c = c->next;
    }
    while (c != NULL && j < y - 1) {
        c = c->next;
        j++;
    }
    j = x - 1;
    while (c != NULL) {
        if (c->val != num[j--]) return false;
        c = c->next;
    }
    return true;
}