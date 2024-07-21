/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
  while ((root != NULL) && (root->val != val)) {
    root = (root->val > val) ? root->left : root->right;
  }

  return root;
}