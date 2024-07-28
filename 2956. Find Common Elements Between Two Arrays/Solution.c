/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int i, *arr = calloc (2, sizeof (int)), hash[101] = {0};
  for (i = 0; i < nums1Size; i++) {
    hash[nums1[i]]++;
  }

  for (i = 0; i < nums2Size; i++) {
    if (hash[nums2[i]] > 0) {
      arr[0] += hash[nums2[i]];
      arr[1] += 1;
      hash[nums2[i]] = -1;
    } else if (hash[nums2[i]] != 0) {
      arr[1] += 1;
    }
  }

  *returnSize = 2;
  return arr;
}