#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {  // Faster than 100% solutions!!!
  int i, j, n = strlen (s);
  char p[n];

  if (n & 1) {
    return false;
  }

  for (i = 0, j = -1; i < n; i++) {
    if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
      p[++j] = s[i];
    } else if ((j < 0) || (s[i] == ')' && p[j] != '(') || (s[i] == ']' && p[j] != '[') || (s[i] == '}' && p[j] != '{')) {
      return false;
    } else {
      j--;
    }
  }

  return j == -1;
}


int main () {
  char *s = "([])";

  printf ("input: %s  output: %s\n", s, isValid (s) ? "true" : "false");

  getchar();
  return 0;
}