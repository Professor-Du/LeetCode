struct Status {
  int lSum, rSum, mSum, iSum;
};

struct Status pushUp (struct Status l, struct Status r) {
  int lSum = fmax (l.lSum, l.iSum + r.lSum);
  int rSum = fmax (r.rSum, r.iSum + l.rSum);
  int iSum = r.iSum + l.iSum;
  int mSum = fmax (fmax (l.mSum, r.mSum), l.rSum + r.lSum);
  return (struct Status) {lSum, rSum, mSum, iSum};
}

struct Status getSub (int *nums, int l, int r) {
  if (l == r) {
    return (struct Status) {nums[l], nums[l], nums[l], nums[l]};
  }

  struct Status lSub = getSub (nums, l, (l + r) / 2);
  struct Status rSub = getSub (nums, (l + r) / 2 + 1, r);

  return pushUp (lSub, rSub);
}

int maxSubArray_2(int* nums, int numsSize){
  return getSub (nums, 0, numsSize - 1).mSum;  // LeeCode Official Solution #2
}




int maxSubArray_1(int* nums, int numsSize){
  int i, preVal, maxVal;

  maxVal = preVal = nums[0];
  for (i = 1; i < numsSize; i++) {
    preVal = preVal < 0 ? nums[i] : preVal + nums[i];
    if (preVal > maxVal) maxVal = preVal;
  }

  return maxVal;
}




int maxSubArray_0(int* nums, int numsSize){
  int i, maxVal, dp[numsSize];

  maxVal = dp[0] = nums[0];
  for (i = 1; i < numsSize; i++) {
    dp[i] = fmax (dp[i - 1] + nums[i], nums[i]);
    if (dp[i] > maxVal) maxVal = dp[i];
  }

  return maxVal;
}