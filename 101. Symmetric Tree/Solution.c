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

bool isMirror(struct TreeNode* n0, struct TreeNode* n1) {
    if ((n0 == NULL) || (n1 == NULL)) {
        return n0 == n1;
    }

    return n0->val == n1->val && isMirror(n0->left, n1->right) && isMirror(n0->right, n1->left);
}

bool isSymmetric(struct TreeNode* root) {  // Faster than 100% solutions!!!
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
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
    // int vals[] = {1,2,2,3,4,4,3};
    // int vals[] = {1,2,2,INF,3,INF,3};  // Level-order
    int vals[] = {1,2,2,3,INF,INF,3};  // Level-order

    struct TreeNode* root = createTree (1, vals, ARRAY_SIZE (vals));

    printf ("input: ");
    for (int i = 0; i < ARRAY_SIZE (vals); i++) {
      if (vals[i] != INF) {
        printf ("%d ", vals[i]);
      } else {
        printf ("? ");
      }
    }

    printf (" output: %s\n", isSymmetric (root) ? "Symmetric" : "Asymmetric");

    freeTree (root);

    getchar ();
    return 0;
}
