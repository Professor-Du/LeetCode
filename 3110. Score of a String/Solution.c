int scoreOfString(char* s) {  // Faster than 100% solutions!!!
    int i, score = 0;
    for (i = 1; s[i] != '\0'; i++) {
      score += abs(s[i] - s[i - 1]);
    }
    return score;
}