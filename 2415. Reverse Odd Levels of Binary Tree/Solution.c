/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traversal (struct TreeNode* root0, struct TreeNode* root1, int level) {
  if (root0 == NULL || root1 == NULL) {
    return;
  }

  if (++level & 1) {
    int temp   = root0->val;
    root0->val = root1->val;
    root1->val = temp;
  }

  traversal(root0->left, root1->right, level);
  traversal(root0->right, root1->left, level);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
  traversal(root->left, root->right, 0);
  return root;
}