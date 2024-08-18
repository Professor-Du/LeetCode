bool isPrefixString(char* s, char** words, int wordsSize) {  // Faster then 100% solutions!!!
  int i, j, k = 0;

  for (i = 0; i < wordsSize; i++) {
    for (j = 0; words[i][j] != '\0'; j++) {
      if (words[i][j] != s[k++]) {
        return false;
      }
    }
    if (s[k] == '\0') {
      return true;
    }
  }

  return false;
}