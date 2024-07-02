#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

bool isNum(char c) {
    return c >= '0' && c <= '9';
}

bool isAlphanumeric(char c) {
    return isUpper(c) || isLower(c) || isNum(c);
}

bool isPalindrome01(char* s) {
    int n = strlen(s);

    for (int i = 0, j = n - 1; i < j;) {
        if (s[i] == s[j]) {
            i++;
            j--;
            continue;
        }

        if (!isAlphanumeric(s[i])) {
            i++;
            continue;
        }

        if (!isAlphanumeric(s[j])) {
            j--;
            continue;
        }

        if (isNum(s[i])) {
            return false;
        }

        if (s[i] - (isUpper(s[i]) ? 'A' : 'a') != s[j] - (isUpper(s[j]) ? 'A' : 'a')) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

bool isPalindrome02(char* s) {
    int n = strlen(s);

    for (int i = 0, j = n - 1; i < j;) {
        if (!isAlphanumeric(s[i])) {
            i++;
            continue;
        }

        if (!isAlphanumeric(s[j])) {
            j--;
            continue;
        }

        if (isLower(s[i])) {
            s[i] = s[i] - 'a' + 'A';
        }
        if (isLower(s[j])) {
            s[j] = s[j] - 'a' + 'A';
        }

        if (s[i] == s[j]) {
            i++;
            j--;
            continue;
        }

        return false;
    }

    return true;
}

#define isUpper(c)        (c >= 'A' && c <= 'Z')
#define isLower(c)        (c >= 'a' && c <= 'z')
#define isNum(c)          (c >= '0' && c <= '9')
#define isAlphanumeric(c) (isUpper(c) || isLower(c) || isNum(c))

bool isPalindrome(char* s) {  // Faster than 100% solutions!!!
    int n = strlen(s);

    for (int i = 0, j = n - 1; i < j;) {
        if (!isAlphanumeric(s[i])) {
            i++;
            continue;
        }

        if (!isAlphanumeric(s[j])) {
            j--;
            continue;
        }

        if (isLower(s[i])) {
            s[i] = s[i] - 'a' + 'A';
        }
        if (isLower(s[j])) {
            s[j] = s[j] - 'a' + 'A';
        }

        if (s[i] == s[j]) {
            i++;
            j--;
            continue;
        }

        return false;
    }

    return true;
}

int main () {
    char s[] = "A man, a plan, a canal: Panama";

    printf ("input: %s  output: %s\n", s, isPalindrome (s) ? "true" : "false");

    getchar ();
    return 0;
}
