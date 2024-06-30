#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* shiftingLetters2 (char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    for (int row = 0; row < shiftsSize; row++) {
        for (int i = shifts[row][0]; i <= shifts[row][1]; i++) {
            s[i] = (s[i] + (shifts[row][2] == 0 ? 25 : 1) - 'a') % 26 + 'a'; 
        }
    }

    return s;
}

char* shiftingLetters3(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int final[shiftsSize];
    memset (final, 0, sizeof (final));
    for (int row = 0; row < shiftsSize; row++) {
        for (int i = shifts[row][0]; i <= shifts[row][1]; i++) {
            final[i] += shifts[row][2] == 0 ? -1 : 1;
        }
    }

    for (int i = 0; i < shiftsSize; i++) {
        s[i] = (s[i] + (final[i] + 26) - 'a') % 26 + 'a'; 
    }

    return s;
}

char* shiftingLetters (char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int *diff;
    int len = strlen (s);

    diff = calloc (len + 1, sizeof (int));

    for (int row = 0; row < shiftsSize; row++) {
        if (shifts[row][2] == 0) {
            diff[shifts[row][0]]--;
            diff[shifts[row][1] + 1]++;
        } else {
            diff[shifts[row][0]]++;
            diff[shifts[row][1] + 1]--;
        }
    }

    for (int i = 0; i < len; i++) {
        if (i > 0) {
            diff[i] = (diff[i] + diff[i - 1]);
        }
        diff[i] %= 26;
        s[i] = (s[i] + (diff[i] + 26) - 'a') % 26 + 'a';
    }

    return s;
}

int main () {
  char *s = NULL;
  char a[] = "dztz";
  int  shifts[][3] = {{0,0,0},{1,1,1}};
  int  **p = (int **) malloc (sizeof (shifts) / sizeof (shifts[0]) * sizeof (int *));
  int  shiftsColSize = 3;

  for (int i = 0; i < sizeof (shifts) / sizeof (shifts[0]); i++) {
    p[i] = (int *) malloc (sizeof (shifts[0]));
    for (int j = 0; j < shiftsColSize; j++) {
      p[i][j] = shifts[i][j];
    }
  }

  s = shiftingLetters (a, p, sizeof (shifts) / sizeof (shifts[0]), &shiftsColSize);
  printf ("%s", s);

  return 0;
}