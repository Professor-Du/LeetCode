/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    int val = head->val;
    struct ListNode **p = &head->next;

    while ((*p) != NULL) {
        if ((*p)->val == val) {
            *p = (*p)->next;
        } else {
            val = (*p)->val;
            p = &(*p)->next;
        }
    }

    return head;
}
