int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i, minVal1 = INT_MAX, minVal2 = INT_MAX;

  for (i = 0; i < nums1Size; i++) {
    minVal1 = fmin (minVal1, nums1[i]);
    minVal2 = fmin (minVal2, nums2[i]);
  }

  return minVal2 - minVal1;
}