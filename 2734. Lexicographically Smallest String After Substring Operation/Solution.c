#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *smallestString (char *s) {
    bool  SubOp = false;

    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == 'a') {
        if (SubOp) {
          break;
        } else if (s[i+1] == '\0') {
          s[i] = 'z';
        }
      } else {
        SubOp = true;
        s[i] -= 1;
      }
    }

    return s;
}

char *smallestString2 (char *s) {
    char  *p = s;
    bool  Flag = false;

    while (*p != '\0') {
        if (*p == 'a') {
            if (Flag) {
                break;
            } else if (*(p + 1) == '\0') {
                *p += 'z' - 'a';
            }
        } else {
            Flag = true;
            *p -= 1;
        }
        p++;
    }

    return s;
}

int main () {
    // char a[] = "cbabc";
    // char a[] = "aa";
    // char a[] = "acbbc";
    char a[] = "leetcode";
    char *s = NULL;

    s = smallestString (a);
    printf ("%s", s);

    return 0;
}