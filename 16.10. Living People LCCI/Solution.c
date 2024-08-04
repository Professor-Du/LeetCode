int maxAliveYear(int* birth, int birthSize, int* death, int deathSize){
  int i, idx = 0, val = 0, maxVal = 0, count[102] = {0};

  for (i = 0; i < birthSize; i++) {
    count[birth[i] - 1900]++;
    count[death[i] - 1899]--;
  }

  for (i = 0; i < 101; i++) {
    val += count[i];
    if (val > maxVal) {
        idx = i;
        maxVal = val;
    }
  }

  return 1900 + idx;
}


int maxAliveYear_better(int* birth, int birthSize, int* death, int deathSize){
  int i, idx = 0, val = 0, maxVal = 0, minYear = INT_MAX, maxYear = 0, count[2002];

  memset(count + 1900, 0, 102 * sizeof (int));

  for (i = 0; i < birthSize; i++) {
    count[birth[i]]++;
    count[death[i] + 1]--;
    minYear = fmin (minYear, birth[i]);
    maxYear = fmax (maxYear, death[i]);
  }

  for (i = minYear; i <= maxYear; i++) {
    val += count[i];
    if (val > maxVal) {
        idx = i;
        maxVal = val;
    }
  }

  return idx;
}

