#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix (char** strs, int strsSize) {
  if (strsSize == 1) {
    return strs[0];
  }

  for (int j = 0; ;j++) {
    for (int i = 1; i < strsSize; i++) {
      if ((strs[i][j] != strs[i - 1][j]) || (strs[i - 1][j] == '\0')) {
        strs[i - 1][j] = '\0';
        return strs[i - 1];
      }
    }
  }

  return "";
}


int main () {
  char *temp[] = {"dog","racecar","car"}; // {"flower","flow","flight"}, ["",""], ["dog","racecar","car"], ["flower"]

  char **s = malloc (sizeof (char *) * sizeof (temp) / sizeof(temp[0]));

  printf ("intput: ");
  for (int i = 0; i < sizeof (temp) / sizeof(temp[0]); i++) {
    s[i] = malloc (sizeof (char) * strlen (temp[i]));
    strcpy (s[i], temp[i]);
    printf ("%s ", s[i]);
  }
  printf (" output: %s\n", longestCommonPrefix (s, sizeof (temp) / sizeof(temp[0])));

  getchar();
  return 0;
}