#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF __INT_MAX__
#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode* root, int *diameter) {
    if (root == NULL) {
        return 0;
    }

    int left  = depth(root->left,  diameter);
    int right = depth(root->right, diameter);

    *diameter = fmax(*diameter, left + right);
    return fmax(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    depth (root, &diameter);
    return diameter;
}

/**
 * Pre-Order Traversal
 */
struct TreeNode* createTree (int id, int *vals, int len) {
  if ((id > len) || (vals[id - 1] == INF)) {
    return NULL;
  }

  struct TreeNode* p = malloc (sizeof (struct TreeNode));
  p->val = vals[id - 1];

  p->left  = createTree (id * 2, vals, len);
  p->right = createTree (id * 2 + 1, vals, len);

  return p;
}

int main () {
    // int vals[] = {1,2,3,4,5};
    int vals[] = {1,2,3,4,5,INF,7,INF,INF,10,INF,INF,INF,INF,15,INF,INF,INF,INF,20,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,31};  // Level-order

    struct TreeNode* root = createTree (1, vals, ARRAY_SIZE (vals));

    printf ("input: ");
    for (int i = 0; i < ARRAY_SIZE (vals); i++) {
      if (vals[i] != INF) {
        printf ("%d ", vals[i]);
      } else {
        printf ("? ");
      }
    }

    printf (" output: %d\n", diameterOfBinaryTree (root));

    getchar ();
    return 0;
}
