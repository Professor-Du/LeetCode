char* getEncryptedString(char* s, int k) {
    int n = strlen (s);
    char *r = malloc (sizeof (char) * n + 1);
    memcpy (r, s + (k % n), n - (k % n));
    memcpy (r + n - (k % n), s, k % n);
    r[n] = '\0';
    return r;
}