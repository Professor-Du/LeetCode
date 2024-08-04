struct PointInfo {
  int   side;
  char  tag;
};

static int cmp (const void *a, const void *b) {
  return ((struct PointInfo *)a)->side - ((struct PointInfo *)b)->side;
}

int maxPointsInsideSquare_draft(int** points, int pointsSize, int* pointsColSize, char* s) {
  int i, cnt = 0, m=pointsSize, n = pointsColSize[0];
  struct PointInfo pInfo[m];
  bool hash['z'+1] = {0};

  for (i = 0; i < m; i++) {
    pInfo[i].side = fmax(abs(points[i][0]), abs(points[i][1]));
    pInfo[i].tag  = s[i];
  }

  qsort (pInfo, m, sizeof (struct PointInfo), cmp);

  cnt = 1; hash[pInfo[0].tag] = true;
  for (i = 1; i < m; i++) {
    cnt = (pInfo[i].side != pInfo[i - 1].side) ? 1 : cnt + 1;
    if (hash[pInfo[i].tag]) {
      return i + 1 - cnt;
    }
    hash[pInfo[i].tag] = true;
  }

  return i;
}


int maxPointsInsideSquare(int** points, int pointsSize, int* pointsColSize, char* s) {
  int i, len, maxLen = INT_MAX, cnt = 0, m=pointsSize, n = pointsColSize[0];
  int minLen['z'+1];

  for (i = 'a'; i <= 'z'; i++) {
    minLen[i] = INT_MAX;;
  }

  for (i = 0; i < m; i++) {
    len = fmax(abs(points[i][0]), abs(points[i][1]));
    if (minLen[s[i]] != INT_MAX) {
      if (len < minLen[s[i]]) {
        maxLen = fmin (maxLen, minLen[s[i]]);
        minLen[s[i]] = len;
      } else {
        maxLen = fmin (maxLen, len);
      }
    } else {
      minLen[s[i]] = len;
    }
  }

  for (i = 'a'; i <= 'z'; i++) {
    if (minLen[i] < maxLen) {
      cnt++;
    }
  }

  return cnt;
}
