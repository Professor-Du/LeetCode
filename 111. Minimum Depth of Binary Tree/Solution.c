#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int traversal (struct TreeNode* root) {
    if ((root->left == NULL) && (root->right == NULL)) {
        return 1;
    } else if (root->left == NULL) {
        return traversal (root->right) + 1;
    } else if (root->right == NULL) {
        return traversal (root->left) + 1;
    } else {
        return fmin (traversal (root->left), traversal (root->right)) + 1;
    }
}

int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return traversal(root);
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
    // int vals[] = {3,9,20,INF,INF,15,7};
    // int vals[] = {1,2,2,3,INF,INF,3,4,INF,INF,4};  // Level-order
    int vals[] = {1,2,3,4,5,INF,6,7,INF,INF,INF,INF,INF,INF,8};  // Level-order

    struct TreeNode* root = createTree (1, vals, ARRAY_SIZE (vals));

    printf ("input: ");
    for (int i = 0; i < ARRAY_SIZE (vals); i++) {
      if (vals[i] != INF) {
        printf ("%d ", vals[i]);
      } else {
        printf ("? ");
      }
    }

    printf (" output: %s\n", isBalanced (root) ? "Balanced" : "Unbalanced");

    freeTree (root);

    getchar ();
    return 0;
}
