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

struct ListNode* createList (int *vals, int num) {
  struct ListNode *head = NULL, **p = &head;

  for (int i = 0; i < num; i++) {
    *p = malloc (sizeof (struct ListNode));
    (*p)->val = vals[i];
    (*p)->next = NULL;
    p = &(*p)->next;
  }

  return head;
}

void freeList (struct ListNode *head) {
  while (head != NULL) {
    struct ListNode *temp = head;
    head = head->next;
    free (temp);
  }
}

void displayList (struct ListNode *head) {
  while (head != NULL) {
    printf ("%d->", head->val);
    head = head->next;
  }
  printf ("null");
}

/**
 * Solution #1 - faster than 45.32% solutions
 */
struct ListNode* mergeTwoList (struct ListNode* h1, struct ListNode* h2) {
    struct ListNode *head = NULL, **p = &head;
    while ((h1 != NULL) && (h2 != NULL)) {
        if (h1->val < h2->val) {
            *p = h1;
            h1 = h1->next;
        } else {
            *p = h2;
            h2 = h2->next;
        }
        p = &(*p)->next;
    }

    *p = (h2 == NULL) ? h1 : h2;

    return head;
}

struct ListNode* sortList_v1(struct ListNode* head) {
    struct ListNode *fast = head, **slow = &head, *mid;
    while ((fast != NULL) && (fast->next != NULL)) {
        slow = &(*slow)->next;
        fast = fast->next->next;
    }

    if (*slow == head) {
        return head;
    }

    mid = *slow;
    *slow = NULL;

    return mergeTwoList (sortList_v1 (head), sortList_v1 (mid));
}

/**
 * Solution #2 - faster than 72.42% solutions
 */
static int cmp (const void *a, const void *b) {
    return (*(struct ListNode**)a)->val - (*(struct ListNode**)b)->val;
}

struct ListNode* sortList_v2(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    int i, j;
    struct ListNode **temp = &head, **p = malloc (sizeof (struct ListNode *) * 50000);
    for (i = 0; head != NULL; i++) {
        p[i] = head;
        head = head->next;
    }

    qsort (p, i, sizeof (struct ListNode *), cmp);

    for (int j = 0; j < i; j++) {
        *temp = p[j];
        temp = &(*temp)->next;
    }
    *temp = NULL;

    return head;
}

/**
 * Solution #3 - faster than 50.12% solutions
 */
struct ListNode* sortList_v3(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    int idx, sublen, totLen = 0;
    struct ListNode dummy, *h1, *h2, *pre, *cur, *temp;
    dummy.next = head;

    while (head !=NULL) {
        head = head->next;
        totLen++;
    }

    for (sublen = 1; sublen < totLen; sublen <<= 1) {
        pre = &dummy; cur = dummy.next;
        while (cur != NULL) {
            h1 = cur;
            for (idx = 1; (idx < sublen) && (cur->next != NULL); idx++) {
              cur = cur->next;
            }

            h2 = cur->next;
            cur->next = NULL;
            cur = h2;
            if (cur != NULL) {
              for (idx = 1; (idx < sublen) && (cur->next != NULL); idx++) {
                cur = cur->next;
              }

                temp = cur->next;
                cur->next = NULL;
                cur = temp;
            }

            pre->next = mergeTwoList (h1, h2);
            while (pre->next != NULL) {
                pre = pre->next;
            }
        }
    }

    return dummy.next;
}


int main () {
  int vals[] = {-1,5,3,4,0};
  struct ListNode *head = createList (vals, ARRAY_SIZE (vals));

  printf ("input: ");
  displayList (head);

  printf (" output: ");
  displayList (head = sortList_v3 (head));

  freeList (head);

  getchar ();
  return 0;
}
