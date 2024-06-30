int lengthOfLastWord(char* s) {
    int i = strlen (s) - 1, n = 0;

    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    while (i >= 0 && s[i] != ' ') {
        i--;
        n++;
    }

    return n;
}