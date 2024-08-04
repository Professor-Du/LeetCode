char* getSmallestString(int n, int k) {
  int i, delta;
  char *str = malloc (sizeof (char) * n + 1);

  for (i = n - 1, k -= n; i >= 0; i--, k -= delta) {
    delta = fmin (k, 25);
    str[i] = 'a' + delta;
  }

  str[n] = '\0';
  return str;
}