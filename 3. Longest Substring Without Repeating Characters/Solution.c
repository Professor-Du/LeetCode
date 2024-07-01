#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring2(char* s) {
    char *pl = s, *pr = s;
    int result = 0, len = 0;

    if (*s == '\0') {
        return 0;
    }

    while (*pr != '\0') {
        char *pm = pl;
        while (pm < pr) {
            if (*pm == *pr) {
                pl = pm + 1;
                len = pr - pl;
                break;
            }
            pm++;
        }

        pr++;
        len++;
        result = max (result, len);
    }

    return result;
}

int lengthOfLongestSubstring_hash(char* s) {  // Faster than 100% solutions!!!
    int result = 0, len = 0;
    int hash[128] = {0};

    len = __INT_MAX__;

    for (int left = 0, right = 0; s[right] != '\0'; right++) {
        if (hash[s[right]] > left) {
            left = hash[s[right]];
            len = right - left;
        }

        len++;
        result = max (result, len);
        hash[s[right]] = right + 1;
    }

    return result;
}

int lengthOfLongestSubstring(char* s) {
    int result = 0, len = 0;

    for (int left = 0, right = 0; s[right] != '\0'; right++) {
        for (int index = left; index < right; index++) {
            if (s[index] == s[right]) {
                left = index + 1;
                len = right - left;
                break;
            }
        }
        len++;
        result = max (result, len);
    }

    return result;
}

int main () {
  char *s = "abcabcbb";

  printf ("inpout: %s  output: %d\n", s, lengthOfLongestSubstring_hash (s));

//   char ch[99];
//   scanf ("%99s", ch);
//   printf ("inpout: %s  output: %d\n", ch, lengthOfLongestSubstring_hash (ch));

  getchar ();
  return 0;
}
