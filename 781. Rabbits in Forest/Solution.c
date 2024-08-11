static int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}
int numRabbits(int* answers, int answersSize) {  // Faster than 100% solutions!!!
  int i, cnt, num;
  qsort (answers, answersSize, sizeof (int), cmp);

  cnt = 1;
  num = answers[0] + 1;
  for (i = 1; i < answersSize; i++) {
    if (answers[i] != answers[i-1] || cnt >= answers[i] + 1) {
      num += answers[i] + 1;
      cnt = 0;
    }
    cnt++;
  }

  return num;
}


int numRabbits_better(int* answers, int answersSize) {
  int i, cnt, num;
  qsort (answers, answersSize, sizeof (int), cmp);

  cnt = answers[0];
  num = cnt + 1;
  for (i = 1; i < answersSize; i++) {
    if (answers[i] != answers[i-1] || cnt == 0) {
      cnt = answers[i] + 1;
      num += cnt;
    }
    cnt--;
  }

  return num;
}