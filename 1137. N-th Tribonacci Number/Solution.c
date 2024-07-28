

int tribonacci(int n){  // Faster than 100% solutions!!!
  int i = -1, t[3] = {0, 1, 1};

  if (n < 3) {
    return t[n];
  }

  for (n = n - 3; n >= 0; n--) {
    i = (i + 1) % 3;
    t[i] = t[0] + t[1] + t[2];
  }

  return t[i];
}