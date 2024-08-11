/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int traversal (struct TreeNode* root) {  // Faster than 100% solutions!!!
  if (root->left == NULL) {  // root->right must be NULL as well
    return root->val;
  }

  int left = (root->val < root->left->val) ? root->left->val : traversal (root->left);
  int right = (root->val < root->right->val) ? root->right->val : traversal (root->right);

  return (root->val == left) ? right : (root->val == right) ? left : fmin (left, right);
}

int findSecondMinimumValue(struct TreeNode* root) {
  int val = traversal (root);
  return (root->val == val) ? -1 : val;
}