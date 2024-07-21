char* toLowerCase(char* s) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))) {
      s[i] |= 0x20;
    }
  }
  return s;
}