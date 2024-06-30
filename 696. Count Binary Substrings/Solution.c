#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int countBinarySubstrings(char* s) {
    bool isCnt0 = true;
    int n0 = 0, n1 = 0, n = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            if (!isCnt0) {
                n += fmin (n0, n1);
                n0 = 1;
                isCnt0 = !isCnt0;
            } else {
                n0++;
            }
        } else {
            if (isCnt0) {
                n += fmin (n0, n1);
                n1 = 1;
                isCnt0 = !isCnt0;
            } else {
                n1++;
            }
        }
    }

    return n + fmin (n0, n1);
}

int main () {
  char *s = "00110011";

  printf ("input: %s, output: %d\n", s, countBinarySubstrings (s));

  getchar ();
  return 0;
}