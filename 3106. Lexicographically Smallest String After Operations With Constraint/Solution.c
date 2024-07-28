char* getSmallestString(char* s, int k) {
    int i, delta, len = strlen (s);
    for (i = 0; (i < len) && (k > 0); i++) {
        if (s[i] == 'a') {
            continue;
        }

        delta = fmin (k, 13);
        if (s[i] + delta > 'z') {
            k -= 26 + 'a' - s[i];
            s[i] = 'a';
        } else if (s[i] - delta <= 'a') {
            k -= s[i] - 'a';
            s[i] = 'a';
        } else {
            k -= delta;
            s[i] -= delta;
        }
    }

    return s;
}