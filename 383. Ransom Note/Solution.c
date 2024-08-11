bool canConstruct(char* ransomNote, char* magazine) {
  int i, hash['z'+1] = {0};
  for (i = 0; ransomNote[i] != '\0'; i++) {
    hash[ransomNote[i]]++;
  }
  for (i = 0; magazine[i] != '\0'; i++) {
    hash[magazine[i]]--;
  }

  for (i = 'a'; i <= 'z'; i++) {
    if (hash[i] > 0) {
      return false;
    }
  }
  return true;
}