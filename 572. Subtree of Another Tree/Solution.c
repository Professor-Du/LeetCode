/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree (struct TreeNode* root, struct TreeNode* subRoot) {
  if (root == NULL || subRoot == NULL) {
    return root == subRoot;
  }

  return (root->val == subRoot->val) && isSameTree (root->left, subRoot->left) && isSameTree (root->right, subRoot->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
  return isSameTree (root, subRoot) || ((root != NULL) && (isSubtree (root->left, subRoot) || isSubtree (root->right, subRoot)));
}