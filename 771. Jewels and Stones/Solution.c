int numJewelsInStones(char* jewels, char* stones) {
  int i, n = 0;
  bool *m = calloc (64, sizeof (bool));
  for (i = 0; jewels[i] != '\0'; i++) {
    m[jewels[i] & 0x3F] = true;
  }

  for (i = 0; stones[i] != '\0'; i++) {
    if (m[stones[i] & 0x3F]) {
      n++;
    }
  }

  return n;
}