/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int               CarryBit = 0;
    struct ListNode** NodePtr  = &l1;  // Pointer to list header or "next"

    while ((l2 != NULL) || (CarryBit != 0)) {
        if ((*NodePtr) == NULL) {
            (*NodePtr) = (struct ListNode*) malloc (sizeof (struct ListNode));
            (*NodePtr)->val = 0;
            (*NodePtr)->next = NULL;
        }

        if (l2 != NULL) {
            (*NodePtr)->val += l2->val;
            l2 = l2->next;
        }

        (*NodePtr)->val += CarryBit;
        CarryBit = 0;

        if ((*NodePtr)->val > 9) {
            (*NodePtr)->val %= 10;
            CarryBit = 1;
        }

        NodePtr = &(*NodePtr)->next;
    }

    return l1;
}