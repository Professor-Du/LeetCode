char* reversePrefix(char* word, char ch) {
  char temp;
  int i, j, n;

  for (n = 0; word[n] != '\0'; n++) {
    if (word[n] == ch) {
      break;
    }
  }

  if (word[n] == '\0') {
    return word;
  }

  for (i = 0, j = n; i < j; i++, j--) {
    temp = word[i];
    word[i] = word[j];
    word[j] = temp;
  }

  return word;
}