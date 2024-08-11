/**
 * Details of this solution:
 * https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/solutions/2874930/1404-yi-chong-zhi-xu-jian-dan-tong-ji-yi-l0ey/
 */

int numSteps(char* s) {  // Faster than 100% solutions!!!
  int i, cnt = 0, len = strlen (s);

  for (i = len- 1; i >= 0; i--) {
    if (s[i] == '1') {
      break;  // Find the last '1'
    }
  }

  if (i == 0) {
    return len - 1;  // Reached the first char
  }

  for (i -= 1; i > 0; i--) {
    if (s[i] == '0') {
      cnt++;
    }
  }

  return cnt + len + 1;
}