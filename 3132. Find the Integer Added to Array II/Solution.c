static int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int minimumAddedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i, j, k, delta;

  qsort (nums1, nums1Size, sizeof (int), cmp);
  qsort (nums2, nums2Size, sizeof (int), cmp);

  for (k = 2; k > 0; k--) {
    delta = nums2[0] - nums1[k];
    for (i = k, j = 0; i < nums1Size; i++) {
      if (nums1[i] + delta == nums2[j]) {
        if (++j >= nums2Size) {
          return delta;
        }
      }
    }
  }

  return nums2[0] - nums1[0];
}