#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]))

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *temp, **p = &list1;

    if (list1 == NULL) {
        return list2;
    }

    while (list2 != NULL) {
        if ((*p)->val > list2->val) {
            temp = *p;
            *p = list2;
            list2 = list2->next;
            (*p)->next = temp;
        } else if ((*p)->next == NULL) {
            (*p)->next = list2;
            break;
        }
        p = &(*p)->next;
    }

    return list1;
}


struct ListNode* mergeTwoLists2(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head = NULL, **temp = &head;

    // if (list1 == NULL) {
    //     return list2;
    // }

    while ((list1 != NULL) && (list2 != NULL)) {
      if (list1->val > list2->val) {
        *temp = list2;
        list2 = list2->next;
      } else {
        *temp = list1;
        list1 = list1->next;
      }

      temp = &(*temp)->next;
    }

    *temp = (list2 == NULL) ? list1 : list2;

    return head;
}


int main () {
  int i, arr1[] = {2,2,4}, arr2[] = {1,3,4,5};
  struct ListNode *list1, *list2, *result, **p;

  printf ("input: list1 = ");
  for (i = 0, p = &list1; i < ARRAY_SIZE (arr1); i++) {
    *p = malloc (sizeof (struct ListNode));
    (*p)->val = arr1[i];
    (*p)->next = NULL;
    p = &(*p)->next;
    printf ("%d ", arr1[i]);
  }

  printf ("list2 = ");
  for (i = 0, p = &list2; i < ARRAY_SIZE (arr2); i++) {
    *p = malloc (sizeof (struct ListNode));
    (*p)->val = arr2[i];
    (*p)->next = NULL;
    p = &(*p)->next;
    printf ("%d ", arr2[i]);
  }

  printf (" output: ");

  result = mergeTwoLists2 (list1, list2);
  while (result != NULL) {
    printf ("%d ", result->val);
    result = result->next;
  }

  getchar ();
  return 0;
}