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

void traversal(struct TreeNode* root, int *val, int* returnSize) {
    if (root == NULL) {
        return;
    }

    val[(*returnSize)++] = root->val;
    traversal(root->left, val, returnSize);
    traversal(root->right, val, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *p = malloc (sizeof (int) * 100);

    *returnSize = 0;
    traversal(root, p, returnSize);
    return p;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal_iteratively(struct TreeNode* root, int* returnSize) {
    int top = 0, *p = malloc (sizeof (int) * 100);
    struct TreeNode **stack = malloc (sizeof (struct TreeNode *) * 100);

    *returnSize = 0;

    while ((root != NULL) || top > 0) {
        if (root != NULL) {
            p[(*returnSize)++] = root->val;
            stack[top++] = root;
            root = root->left;
        } else {
            root = stack[--top];
            root = root->right;
        }
    }

    return p;
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
    int num, *p, vals[] = {1,INF,2,INF,INF,3,INF};  // Level-order
    struct TreeNode* root = createTree (1, vals, ARRAY_SIZE (vals));

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

    freeTree (root);

    getchar ();
    return 0;
}
