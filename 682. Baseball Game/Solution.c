int str2int (char *s) {
  int i, n, neg = false;

  if (*s == '-') {
    neg = true;
    s++;
  }

  for (i = 0, n = 0; s[i] != '\0'; i++) {
    n = n * 10 + s[i] - '0';
  }

  return neg ? -n : n;
}

int calPoints(char** operations, int operationsSize) {
  int i, points = 0, cnt = 0, records[1000];

  for (i = 0; i < operationsSize; i++) {
    switch (operations[i][0]) {
      case '+':
        records[cnt] = records[cnt - 1] + records[cnt - 2];
        cnt++;
        break;

      case 'D':
        records[cnt] = records[cnt - 1] * 2;
        cnt++;
        break;

      case 'C':
        cnt--;
        break;

      default:
        records[cnt] = str2int (operations[i]);
        cnt++;
        break;
    }
  }

  for (i = 0; i < cnt; i++) {
    points += records[i];
  }

  return points;
}



int calPoints(char** operations, int operationsSize) {  // Faster than 100% solutions!!!
  int i, points, cnt = 0, records[1000];

  for (i = 0; i < operationsSize; i++) {
    switch (operations[i][0]) {
      case '+':
        records[cnt] = records[cnt - 1] + records[cnt - 2];
        cnt++;
        break;

      case 'D':
        records[cnt] = records[cnt - 1] * 2;
        cnt++;
        break;

      case 'C':
        cnt--;
        break;

      default:
        records[cnt] = atoi (operations[i]);
        cnt++;
        break;
    }
  }

  for (i = 0, points = 0; i < cnt; i++) {
    points += records[i];
  }

  return points;
}