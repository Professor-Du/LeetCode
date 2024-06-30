#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char   symbol;
    short  value;
} ROMAN_ENTRY;


int romanToInt_stupid(char* s) {  // stupid solution!
    ROMAN_ENTRY  Roman2IntTable[] = {
        { 'I',    1    },
        { 'V',    5    },
        { 'X',    10   },
        { 'L',    50   },
        { 'C',    100  },
        { 'D',    500  },
        { 'M',    1000 }
    };
    
    int result = 0, preVal = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = 0; j < 7; j++) {
            if (Roman2IntTable[j].symbol == s[i]) {
                result += (preVal >= Roman2IntTable[j].value) ? preVal : -preVal;
                preVal = Roman2IntTable[j].value;
                break;
            }
        }
    }

    return result + preVal;
}


int romanToInt(char* s) {
    int result = 0, preVal = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        int curVal;

        switch (s[i]) {
            case 'I': curVal = 1;    break;
            case 'V': curVal = 5;    break;
            case 'X': curVal = 10;   break;
            case 'L': curVal = 50;   break;
            case 'C': curVal = 100;  break;
            case 'D': curVal = 500;  break;
            case 'M': curVal = 1000; break;
            default : curVal = 0;    break;
        }
    
        result += (preVal >= curVal) ? preVal : -preVal;
        preVal = curVal;
    }

    return result + preVal;
}


int main () {
    char *s = "MCMXCIV";

    printf ("input: %s  output: %d\n", s, romanToInt (s));

    getchar ();
    return 0;
}
