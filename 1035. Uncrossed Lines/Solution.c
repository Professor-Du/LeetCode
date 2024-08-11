int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {  // Faster than 100% solutions!!! But it is done based on community solutions
  int i, j, dp[nums1Size + 1][nums2Size + 1];

  for (j = 0; j <= nums2Size; j++) {
    dp[0][j] = 0;
  }

  for (i = 1; i <= nums1Size; i++) {
    dp[i][0] = 0;
    for (j = 1; j <= nums2Size; j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;  // equals to max (dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1])
      } else {
        dp[i][j] = fmax (dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[nums1Size][nums2Size];
}