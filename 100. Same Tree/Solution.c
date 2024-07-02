#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF               __INT_MAX__
#define ARRAY_SIZE(arr)   (sizeof (arr) / sizeof (arr[0]))

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == q) {
        return true;
    }

    if ((p == NULL) || (q == NULL)) {
        return false;
    }

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode * createTree (int id, int *vals, int len) {
    if ((id > len) || vals[id - 1] == INF) {
        return NULL;
    }

    struct TreeNode *p = malloc (sizeof (struct TreeNode));

    p->val   = vals[id - 1];
    p->left  = createTree (id * 2, vals, len);
    p->right = createTree (id * 2 + 1, vals, len);

    return p;
}

void freeTree (struct TreeNode *root) {
    if (root == NULL) {
      return;
    }

    freeTree (root->left);
    freeTree (root->right);
    free (root);
}

int main () {
    int vals0[] = {1,2,3};
    int vals1[] = {1,2,3,4,5,INF,7,INF,INF,10,INF,INF,INF,INF,15,INF,INF,INF,INF,20,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,31};  // Level-order

    struct TreeNode* root0 = createTree (1, vals1, ARRAY_SIZE (vals1));
    struct TreeNode* root1 = createTree (1, vals1, ARRAY_SIZE (vals1));

    printf ("input: ");
    for (int i = 0; i < ARRAY_SIZE (vals0); i++) {
      if (vals0[i] != INF) {
        printf ("%d ", vals0[i]);
      } else {
        printf ("? ");
      }
    }

    printf ("input: ");
    for (int i = 0; i < ARRAY_SIZE (vals1); i++) {
      if (vals1[i] != INF) {
        printf ("%d ", vals1[i]);
      } else {
        printf ("? ");
      }
    }

    printf (" output: %s\n", isSameTree (root0, root1) ? "same" : "different");

    freeTree (root0);
    freeTree (root1);

    getchar ();
    return 0;
}
