char* findLatestTime(char* s) {  // Faster than 100% solutions!!!
    if (s[0] == '?') {
      s[0] = ((s[1] <= '1') || (s[1] == '?')) ? '1' : '0';
    }
    if (s[1] == '?') {
      s[1] = (s[0] == '1') ? '1' : '9';
    }
    if (s[3] == '?') {
      s[3] = '5';
    }
    if (s[4] == '?') {
      s[4] = '9';
    }

    return s;
}