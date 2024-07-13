/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void traversal (struct TreeNode *root, int *vals, int *num) {
  if (root == NULL) {
    return;
  }
  traversal (root->left, vals, num);
  vals[(*num)++] = root->val;
  traversal (root->right, vals, num);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *vals = malloc (sizeof (struct TreeNode) * 100);

    *returnSize = 0;
    traversal (root, vals, returnSize);

    return vals;
}