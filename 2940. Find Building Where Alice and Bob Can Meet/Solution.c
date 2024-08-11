void build(int l, int r, int rt, int heights[], int n, int *zd) {
    if (l == r) {
        zd[rt] = heights[l - 1];
        return;
    }

    int mid = (l + r) >> 1;
    build(l, mid, rt << 1, heights, n, zd);
    build(mid + 1, r, rt << 1 | 1, heights, n, zd);
    zd[rt] = (zd[rt << 1] > zd[rt << 1 | 1]) ? zd[rt << 1] : zd[rt << 1 | 1];
}

int query(int pos, int val, int l, int r, int rt, int *zd) {
    if (val >= zd[rt]) {
        return 0;
    }

    if (l == r) {
        return l;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) {
        int res = query(pos, val, l, mid, rt << 1, zd);
        if (res != 0) {
            return res;
        }
    }
    return query(pos, val, mid + 1, r, rt << 1 | 1, zd);
}

int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = heightsSize;
    int zd[n * 4];
    memset(zd, 0, sizeof(zd));
    build(1, n, 1, heights, n, zd);

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (a == b || heights[a] < heights[b]) {
            ans[i] = b;
            continue;
        }
        ans[i] = query(b + 1, heights[a], 1, n, 1, zd) - 1;
    }
    *returnSize = queriesSize;
    return ans;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftmostBuildingQueries_timeout(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  int i, j, idx1, idx2, *ans = malloc (sizeof (int) * queriesSize);

  for (i = 0; i < queriesSize; i++) {
    if (queries[i][0] == queries[i][1]) {
      ans[i] = queries[i][0];
      continue;
    }
    if (queries[i][0] < queries[i][1]) {
      idx1 = queries[i][0];
      idx2 = queries[i][1];
    } else {
      idx1 = queries[i][1];
      idx2 = queries[i][0];
    }

    if (heights[idx1] < heights[idx2]) {
      ans[i] = idx2;
      continue;
    }
    ans[i] = fmax(heights[idx1], heights[idx2]);

    for (j = idx2 + 1; j < heightsSize; j++) {
      if (ans[i] < heights[j]) {
        ans[i] = j;
        break;
      }
    }
    if (j >= heightsSize) {
      ans[i] = -1;
    }
  }

  *returnSize = queriesSize;
  return ans;
}