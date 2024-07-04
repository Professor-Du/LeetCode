#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

int detectCycle(struct ListNode *head, struct ListNode *node) {
    bool cycle = false; int pos = 0;
    struct ListNode *p0 = head, *p1 = head;

    while ((p1 != NULL) && (p1->next != NULL)) {
        p0 = p0->next;
        p1 = p1->next->next;
        if (p0 == p1) {
            cycle = true;
            break;
        }
    }

    if (!cycle) {
        node = NULL;
        return -1;
    }

    p0 = head;
    while (p0 != p1) {
        p0 = p0->next;
        p1 = p1->next;
        pos++;
    }

    node = p0;
    return pos;
}

struct ListNode* createList (int *vals, int len, int pos) {
    struct ListNode *head, **p = &head, *temp = NULL;

    for (int i = 0; i < len; i++) {
        (*p) = malloc (sizeof (struct ListNode));
        (*p)->val = vals[i];
        (*p)->next = NULL;
        if (i == pos) {
            temp = *p;
        }

        p = &(*p)->next;
    }

    (*p) = temp;

    return head;
}

void freeList (struct ListNode* head, int pos) {
    int cnt = 0;
    struct ListNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        if (cnt++ == pos) {
            temp->next = NULL;
            continue;
        } else {
            free(temp);
        }
    }
}

int main () {
    int a[] = {3,2,0,-4};
    int pos = 1;

    struct ListNode *temp, *head = createList (a, ARRAY_SIZE (a), pos);

    printf ("input: pos=%d list=", pos);
    for (int i = 0; i < ARRAY_SIZE (a); i++) {
        printf ("%d ", a[i]);
    }

    printf (" output: %d\n", detectCycle (head, temp));

    freeList (head, pos);
    getchar ();
    return 0;
}
