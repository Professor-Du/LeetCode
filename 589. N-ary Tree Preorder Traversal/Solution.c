#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INF               __INT_MAX__
#define ARRAY_SIZE(arr)   (sizeof (arr) / sizeof (arr[0]))
#define N_ARY             3

/**
 * Definition for a binary tree node.
 */
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void traversal (struct Node* root, int *vals, int* num) {
    if (root == NULL) {
        return;
    }

    vals[(*num)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        traversal (root->children[i], vals, num);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    int *vals = malloc (sizeof (int) * 10000);
    *returnSize = 0;
    traversal (root, vals, returnSize);

    return vals;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal_iteratively(struct Node* root, int* returnSize) {
    int index = 0, top = -1, *vals = malloc (sizeof (int) * 10000), *stackIndex = malloc (sizeof (int) * 10000);
    struct Node **stackNode = malloc (sizeof (struct Node *) * 10000);

    *returnSize = 0;

    while ((root != NULL) || (top > -1)) {
        if (root != NULL) {
            vals[(*returnSize)++] = root->val;

            top++;
            stackNode[top] = root;
            stackIndex[top] = 1;

            root = (root->numChildren > 0) ? root->children[0] : NULL;
        } else {
            root = stackNode[top];
            index = stackIndex[top];
            if (index >= root->numChildren) {
                root = NULL;
                top--;
            } else {
                root = root->children[index];
                stackIndex[top]++;
            }
        }
    }

    return vals;
}

struct Node * createNaryTree (int N, int id, int *vals, int len) {
    if ((id > len) || vals[id - 1] == INF) {
        return NULL;
    }

    struct Node *temp, *p = malloc (sizeof (struct Node));

    p->val = vals[id - 1];
    p->children = malloc (sizeof (struct Node *) * N);
    p->numChildren = 0;

    for (int i = 0; i < N; i++) {
        temp = createNaryTree (N, (id - 1) * N + 2 + i, vals, len);
        p->children[i] = temp;
        if (temp != NULL) {
            p->numChildren++;
        }
    }

    return p;
}

void freeNaryTree (struct Node *root) {
    if (root == NULL) {
      return;
    }

    for (int i = 0; i < root->numChildren; i++) {
        freeNaryTree (root->children[i]);
    }

    free (root->children);
    free (root);
}

int main () {
    int num, *p, vals[] = {1,3,2,4,5,6};  // Level-order
    struct Node* root = createNaryTree (N_ARY, 1, vals, ARRAY_SIZE (vals));

    printf ("input: ");
    for (int i = 0; i < ARRAY_SIZE (vals); i++) {
      if (vals[i] != INF) {
        printf ("%d ", vals[i]);
      } else {
        printf ("? ");
      }
    }

    printf (" output: ");
    p = preorderTraversal_iteratively (root, &num);
    for (int i = 0; i < num; i++) {
        printf ("%d ", p[i]);
    }

    freeNaryTree (root);

    getchar ();
    return 0;
}
