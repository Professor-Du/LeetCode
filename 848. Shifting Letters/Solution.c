#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *shiftingLetters2 (char* s, int* shifts, int shiftsSize) {

    for (int StrId = 0; StrId < shiftsSize; StrId++) {
        int ShiftVal = 0;
        for (int ShfitId = StrId; ShfitId < shiftsSize; ShfitId++) {
            ShiftVal += shifts[ShfitId] % 26;
        }
        s[StrId] = (s[StrId] + ShiftVal - 'a') % 26 + 'a';
    }

    return s;
}

char *shiftingLetters (char* s, int* shifts, int shiftsSize) {
    // shifts[shiftsSize - 1] %= 26;
    for (int i = shiftsSize - 2; i >= 0; i--) {
        shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }

    for (int i = 0; i < shiftsSize; i++) {
        s[i] = (s[i] + shifts[i] - 'a') % 26 + 'a';
    }

    return s;
}

int main () {
  char *s = NULL;
  char a[] = "mkgfzkkuxownxvfvxasy";
  int  shifts[] = {505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513};

  s = shiftingLetters (a, shifts, sizeof (shifts) / sizeof (shifts[0]));
  printf ("%s", s);

  return 0;
}