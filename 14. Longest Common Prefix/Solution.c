#include <stdio.h>
#include <stdlib.h>


char* longestCommonPrefix(char** strs, int strsSize) {  // Faster than 100% solutions!!!
  int i, j, max_len = 201;
  char *result = malloc (max_len * sizeof (char));

  if (strsSize == 1) {
    return strs[0];
  }

  for (j = 0; ;j++) {
    for (i = 1; i < strsSize; i++) {
      if ((strs[i][j] != strs[i - 1][j]) || (strs[i][j] == '\0')) {
        result[j] = '\0';
        return result;
      }
    }

    result[j] = strs[0][j];
  }

  result[j + 1] = '\0';
  return result;
}


int main () {
  char *s[] = {"dog","racecar","car"}; // {"flower","flow","flight"}, ["",""], ["dog","racecar","car"], ["flower"]

  printf ("intput: ");
  for (int i = 0; i < sizeof (s) / sizeof(s[0]); i++) {
    printf ("%s ", s[i]);
  }
  printf (" output: %s\n", longestCommonPrefix (s, sizeof (s) / sizeof(s[0])));

  getchar();
  return 0;
}