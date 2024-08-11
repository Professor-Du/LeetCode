/**
 * Details of this solution:
 * https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/solutions/2870416/yi-chong-tong-su-yi-dong-qie-ji-bai-1000-agzd/
 */

int findIntegers(int n) {
  int i, cnt = 0, preBit = 0, dp[32] = {0};

  dp[0] = 1; dp[1] = 2;
  for (i = 2; i < 32; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  for (i = 30; i >= 0; i--) {
    if ((n & (1 << i)) == 0) {
      preBit = 0;
      continue;
    }
    cnt += dp[i];
    if (preBit != 0) {
      cnt--;
      break;
    }
    preBit = 1;
  }

  return cnt + 1;
}