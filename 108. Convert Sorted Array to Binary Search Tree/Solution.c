struct TreeNode* create (int *nums, int left, int right) {
  if (left > right) {
    return NULL;
  }

  int mid = (left + right) / 2;
  struct TreeNode *p = malloc (sizeof (struct TreeNode));
  p->val = nums[mid];
  p->left = create (nums, left, mid - 1);
  p->right = create (nums, mid + 1, right);

  return p;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  return create (nums, 0, numsSize - 1);
}