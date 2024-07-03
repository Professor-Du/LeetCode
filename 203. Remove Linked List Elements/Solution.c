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

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **p = &head;

    while ((*p) != NULL) {
        if ((*p)->val == val) {
            *p = (*p)->next;
            continue;
        }
        p = &(*p)->next;
    }

    return head;
}

struct ListNode* createList (int *a, int n) {
    struct ListNode *head, **p = &head;

    for (int i = 0; i < n; i++) {
        *p = malloc (sizeof (struct ListNode));
        (*p)->val = a[i];
        (*p)->next = NULL;
        p = &(*p)->next;
    }

    return head;
}

void freeList (struct ListNode *head) {
    struct ListNode *temp = head;
    while (head != NULL) {
        temp = head;
        free (temp);
        head = head->next;
    }
}

int main () {
    // int a[] = {7,7,7,7,7,7,7};
    // int val = 7;
    int a[] = {1,2,6,3,4,5,6};
    int val = 6;

    struct ListNode *temp, *head = createList (a, ARRAY_SIZE (a));

    printf ("input: ");
    for (temp = head; temp != NULL; temp = temp->next) {
        printf ("%d ", temp->val);
    }

    printf (" output: ");
    for (temp = removeElements (head, val); temp != NULL; temp = temp->next) {
        printf ("%d ", temp->val);
    }

    getchar ();
    return 0;
}
