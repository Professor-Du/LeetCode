static int cmp (const void *a, const void *b) {
  return (*(int **)a)[0] - (*(int **)b)[0];
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
  qsort (meetings, meetingsSize, sizeof (int) * (*meetingsColSize), cmp);

  int i, end = meetings[0][1], meetingDays = end - meetings[0][0] + 1;
  for (i = 1; i < meetingsSize; i++) {
    if (meetings[i][0] <= end) {
      if (meetings[i][1] > end) {
        meetingDays += meetings[i][1] - end;
        end = meetings[i][1];
      }
    } else {
      end = meetings[i][1];
      meetingDays += meetings[i][1] - meetings[i][0] + 1;
    }
  }

  return days - meetingDays;
}