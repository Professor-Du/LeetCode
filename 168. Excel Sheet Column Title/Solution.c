char* convertToTitle(int columnNumber) {
  int i;
  char *s = malloc (sizeof (char) * 8);

  s[7] = '\0';

  for (i = 6; columnNumber > 0; i--) {
    s[i] = ((columnNumber - 1) % 26) + 'A';
    columnNumber = (columnNumber - 1) / 26;
  }

  return s + i + 1;
}