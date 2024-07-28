int maximum69Number (int num) {  // Faster than 100% solutions
  int i = 0, idx = -1, val = num;
  for (i = 0; val > 0; i++) {
    if ((val % 10) == 6) {
      idx = i;
    }
    val /= 10;
  }
  return num + 3 * pow (10, idx);  // Internersting
}