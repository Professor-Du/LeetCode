int minChanges(int n, int k) {  // Faster than 100% solutions!!!
    if ((n & k) != k) {
      return -1;
    }

    int cnt = 0;
    n = n & (~k);
    while (n > 0) {
      n &= n - 1;
      cnt++;
    }

    return cnt;
}