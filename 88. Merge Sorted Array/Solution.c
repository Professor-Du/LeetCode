void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {  // Faster than 100% solutions!!!
    for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; k--) {
      if (j < 0 || (i >= 0 && nums1[i] >= nums2[j])) {
        nums1[k] = nums1[i--];
      } else {
        nums1[k] = nums2[j--];
      }
    }
}