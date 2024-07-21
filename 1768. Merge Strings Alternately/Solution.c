char * mergeAlternately(char * word1, char * word2){
    int i, j, len1 = strlen (word1), len2 = strlen (word2), totLen = len1 + len2;
    char *w = malloc (sizeof (char) * (totLen + 1));

    for (i = 0, j = 0; (i < len1) || (i < len2); i++) {
        if (i < len1) {
            w[j++] = word1[i];
        }

        if (i < len2) {
            w[j++] = word2[i];
        }
    }

    w[totLen] = '\0';

    return w;
}