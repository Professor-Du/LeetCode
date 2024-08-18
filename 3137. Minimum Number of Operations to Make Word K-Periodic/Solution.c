struct HashTable {
  char*  key;
  int    val;
  UT_hash_handle hh;
};

int minimumOperationsToMakeKPeriodic(char* word, int k) {
  int i, max = 0, sum = 0;
  struct HashTable *hashEntry, *hashHead = NULL;

  for (i = 0; word[i] != '\0'; i += k) {
    char *key = malloc (sizeof (char) * (k + 1));

    key[k] = '\0';
    hashEntry = NULL;
    memcpy (key, word + i, sizeof (char) * k);

    HASH_FIND_STR (hashHead, key, hashEntry);
    if (hashEntry != NULL) {
      hashEntry->val++;
    } else {
      hashEntry = malloc (sizeof (struct HashTable));
      hashEntry->key = key;
      hashEntry->val = 1;
      HASH_ADD_STR (hashHead, key, hashEntry);
    }
  }

  for (hashEntry = hashHead; hashEntry != NULL; hashEntry = hashEntry->hh.next) {
    sum += hashEntry->val;
    max = fmax (max, hashEntry->val);
  }

  return sum - max;
}