int digitSum (int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int getLucky(char* s, int k) {  // Faster then 100% solutions!!!
  int i, sum = 0;
  for (i = 0; s[i] != '\0'; i++) {
    sum += digitSum (s[i] - '`');  // '`' = 'a' - 1
  }

  for (k -= 1; k > 0; k--) {
    sum = digitSum (sum);
  }

  return sum;
}