#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p0 = NULL, *p1 = head, *temp;

    while (p1 != NULL) {
        temp = p1->next;
        p1->next = p0;
        p0 = p1;
        p1 = temp;
    }

    return p0;
}

struct ListNode* reverseList_recursively(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    struct ListNode* newHead = reverseList_recursively(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main () {
    int a[] = {1,2,3,4,5};

    struct ListNode *temp, *head, **p = &head;  // = malloc (sizeof (struct ListNode));

    for (int i = 0; i < ARRAY_SIZE (a); i++) {
        *p = malloc (sizeof (struct ListNode));
        (*p)->val = a[i];
        (*p)->next = NULL;
        p = &(*p)->next;
    }

    printf ("input: ");
    for (temp = head; temp != NULL; temp = temp->next) {
        printf ("%d ", temp->val);
    }
    
    printf (" output: ");
    for (temp = reverseList_recursively (head); temp != NULL; temp = temp->next) {
        printf ("%d ", temp->val);
    }

    getchar ();
    return 0;
}
