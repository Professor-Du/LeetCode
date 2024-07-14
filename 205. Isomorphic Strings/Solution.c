#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <uthash.h>  // unstandard library

typedef struct {
  char  key;
  char  val;
  UT_hash_handle  hh;
} HASH_TABLE;

bool isIsomorphic(char* s, char* t) {
    char x, y;
    HASH_TABLE *hashEntry, *sHashTable = NULL, *tHashTable = NULL;

    for (int i = 0; s[i] != '\0'; i++) {
      x = s[i]; y = t[i];
      HASH_FIND (hh, sHashTable, &x, sizeof (char), hashEntry);
      if (hashEntry == NULL) {
        hashEntry = malloc (sizeof (HASH_TABLE));
        hashEntry->key = x;
        hashEntry->val = y;
        HASH_ADD (hh, sHashTable, key, sizeof (char), hashEntry);
      } else if (hashEntry->val != y) {
        return false;
      }

      HASH_FIND (hh, tHashTable, &y, sizeof (char), hashEntry);
      if (hashEntry == NULL) {
        hashEntry = malloc (sizeof (HASH_TABLE));
        hashEntry->key = y;
        hashEntry->val = x;
        HASH_ADD (hh, tHashTable, key, sizeof (char), hashEntry);
      } else if (hashEntry->val != x) {
        return false;
      }
    }

  return true;
}

bool isIsomorphic_best(char* s, char* t) {  // Faster than 100% solutions!!!
    char x, y, *hash1 = calloc (128, sizeof (char)), *hash2 = calloc (128, sizeof (char));
    for (int i = 0; s[i] != '\0'; i++) {
        x =s[i]; y = t[i];
        if (hash1[x] == 0) {
            hash1[x] = y;
        } else if (hash1[x] != y) {
            return false;
        }

        if (hash2[y] == 0) {
            hash2[y] = x;
        } else if (hash2[y] != x) {
            return false;
        }
    }

    return true;
}

int main () {
  char *s = "paper", *t = "title";

  printf ("input: %s %s  output: %s", s, t, isIsomorphic_best (s, t) ? "true" : "flase");

  getchar ();
  return 0;
}