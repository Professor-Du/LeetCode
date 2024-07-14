/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getMinNode (struct ListNode **lists, int listsSize, int *cnt) {
  int minIdx = listsSize, minVal = INT_MAX;
  
  *cnt = 0;
  
  for (int i = 0; i < listsSize; i++) {
    if (lists[i] == NULL) {
      continue;
    }
    if (minVal > lists[i]->val) {
      minIdx = i;
      minVal = lists[i]->val;
    }
    (*cnt)++;
  }

  if (minIdx >= listsSize) {
    return NULL;
  }
  
  struct ListNode *minNode = lists[minIdx];
  lists[minIdx] = minNode->next;
  
  return minNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  int cnt;
  struct ListNode *head, **p = &head;
  
  while (((*p) = getMinNode (lists, listsSize, &cnt)) != NULL && cnt > 1) {
    p = &(*p)->next;
  }
  
  return head;
}