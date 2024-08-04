/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
  int i, sum, maxSum = INT_MIN, level = 1, maxLevel = 1, currTop = 0, nextTop = 0;
  struct TreeNode *p, **currStack = malloc (sizeof (struct TreeNode *) * 10000), **nextStack = malloc (sizeof (struct TreeNode *) * 10000);

  currStack[currTop++] = root;
  while (currTop > 0) {
    sum = 0;

    while (currTop > 0) {
      p = currStack[--currTop];
      sum += p->val;

      if (p->left != NULL) {
        nextStack[nextTop++] = p->left;
      }
      if (p->right != NULL) {
        nextStack[nextTop++] = p->right;
      }
    }

    if (maxSum < sum) {
      maxSum = sum;
      maxLevel = level;
    }
    level++;

    currTop = nextTop;
    nextTop = 0;

    p = (struct TreeNode *) currStack;
    currStack = nextStack;
    nextStack = (struct TreeNode **) p;
  }

  return maxLevel;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum_better(struct TreeNode* root) {
  int n, sum, maxSum = INT_MIN, level = 1, maxLevel = 1, head = 0, rear = 0;
  struct TreeNode *p, **queue = malloc (sizeof (struct TreeNode *) * 10001);

  queue[rear++] = root;
  while (head != rear) {
    for (sum = 0, n = rear; head < n; head++) {
      p = queue[head];
      sum += p->val;
      if (p->left != NULL) {
        queue[rear++] = p->left;
      }
      if (p->right != NULL) {
        queue[rear++] = p->right;
      }
    }

    if (maxSum < sum) {
      maxSum = sum;
      maxLevel = level;
    }
    level++;
  }

  return maxLevel;
}