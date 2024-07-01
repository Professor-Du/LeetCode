#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkRecord(char* s) {
    int cntA = 0, cntL = 0, maxL = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'A': cntA++; maxL = fmax(maxL, cntL); cntL = 0; break;
            case 'P': maxL = fmax(maxL, cntL); cntL = 0; break;
            case 'L': cntL++; break;
        }
    }

    return cntA < 2 && fmax(maxL, cntL) < 3;
}

bool checkRecord_best(char* s) {
    int cntA = 0, cntL = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'A': cntA++; cntL = 0; break;
            case 'P': cntL = 0; break;
            case 'L': cntL++; break;
        }

        if (cntA >= 2 || cntL >= 3) {
          return false;
        }
    }

    return true;
}

int main () {
    char *s = "PPALLL";

    printf ("input: %s  output: %s\n", s, checkRecord_best (s) ? "true" : "false");

    getchar ();
    return 0;
}
