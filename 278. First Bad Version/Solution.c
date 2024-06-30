#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mBadVersion;

void setBadVersion (int n) {
  mBadVersion = n;
}

int isBadVersion (int n) {
  return n >= mBadVersion;
}

int firstBadVersion(int n) {
  long long left = 1, right = n, middle = (left + right) / 2;  // sizeof (long) equals to 8 in leetcode but 4 here.

  if (isBadVersion (1)) {
    return 1;
  } else if (!isBadVersion (n - 1)) {
    return n;
  }

  while (left < right) {
    if (!isBadVersion ((int) middle)) {
      left = middle + 1;
    } else {
      right = middle;
    }
    middle = (left + right) / 2;
  }

  return (int) middle;
}


int main () {
  int n = 2126753390, bad = 1702766719;

  setBadVersion (bad);
  printf("intput: n=%d, bad=%d  output: %d\n", n, bad, firstBadVersion(n));

  getchar ();
  return 0;
}