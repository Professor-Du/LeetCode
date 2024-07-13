#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define INF               __INT_MAX__
#define ARRAY_SIZE(arr)   (sizeof (arr) / sizeof (arr[0]))
#define N_ARY             3

/**
 * Definition for a Node.
 */
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int maxDepth(struct Node* root) {  // Faster than 100% solutions!!!
    if (root == NULL) {
        return 0;
    }

    int depth = 1;
    for (int i = 0; i < root->numChildren; i++) {
        depth = fmax (depth, maxDepth (root->children[i]) + 1);
    }

    return depth;
}

typedef struct {
  struct Node  *pNode;   // pointer to a node
  int          childIdx; // index of node's children
} NODE_STACK;

int maxDepth_iteratively(struct Node* root) {
  int idx, top = -1, depth = 0;
  NODE_STACK *stack = malloc (sizeof (NODE_STACK) * 1000);

  while ((root != NULL) || (top > -1)) {
    if (root != NULL) {
      top++;
      stack[top].pNode = root;
      stack[top].childIdx = 1;

      depth = fmax (depth, top + 1);

      root = (root->numChildren > 0) ? root->children[0] : NULL;
    } else {
      root = stack[top].pNode;
      idx = stack[top].childIdx;

      if (idx >= root->numChildren) {
        top--;
        root = NULL;
      } else {
        root = root->children[idx];
        stack[top].childIdx++;
      }
    }
  }

    return depth;
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

    printf (" output: %d\n", maxDepth_iteratively (root));

    freeNaryTree (root);

    getchar ();
    return 0;
}