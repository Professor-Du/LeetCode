/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traversal (struct TreeNode *root, int parent, int grandParent, int *sum) {
  if (root == NULL) {
    return;
  }
  if ((grandParent & 1) == 0) {
    *sum += root->val;
  }
  grandParent = parent;
  parent = root->val;

  traversal (root->left, parent, grandParent, sum);
  traversal (root->right, parent, grandParent, sum);
}

int sumEvenGrandparent(struct TreeNode* root) {
  int sum = 0;
  traversal (root, 1, 1, &sum);
  return sum;

}