bool isVowel (char c) {
    return c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
           c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u';
}

char* reverseVowels(char* s) {  // Faster than 100% solutions!!!
    char temp;

    for (int i = 0, j = strlen (s); i < j;) {
        if (!isVowel (s[i])) {
            i++;
            continue;
        }
        if (!isVowel (s[j])) {
            j--;
            continue;
        }

        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
    
    return s;
}