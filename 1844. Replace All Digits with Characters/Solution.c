#include <stdlib.h>

char* replaceDigits(char* s) {  // Faster than 100% solutions!!!
    for (int i = 0; s[i] != '\0'; i++) {
      if (i & 1) {
            s[i] += s[i- 1] - '0';
        }
    }

    return s;
}

int main () {
  char a[] = "a1c1e1";
  char *s = NULL;

  s = replaceDigits (a);
  printf ("%s\n", s);

  return 0;
}
