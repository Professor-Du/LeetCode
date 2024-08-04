int findWinningPlayer(int* skills, int skillsSize, int k) {
  int i, winIdx = 0, winCnt = 0;

  for (i = 1; i < skillsSize; i++) {
    if (skills[winIdx] < skills[i]) {  // New winner shows up
      winIdx = i;
      winCnt = 0;
    }
    if (++winCnt >= k) {
      return winIdx;
    }
  }

  return winIdx;
}


int findWinningPlayer_draft(int* skills, int skillsSize, int k) {
  int i, winIdx = 0, *winTimes = calloc (skillsSize, sizeof (int));

  for (i = 1; i < skillsSize; i++) {
    if (skills[winIdx] < skills[i]) {  // New winner shows up
      winIdx = i;
    }
    if (++winTimes[winIdx] >= k) {
      return winIdx;
    }
  }

  return winIdx;
}