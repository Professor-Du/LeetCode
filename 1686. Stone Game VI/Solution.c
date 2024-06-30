#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int oriIndex;
    int sumValue;
} CMP_STRUCT;

static int cmp (const void *a, const void *b) {
  return ((CMP_STRUCT *) b)->sumValue - ((CMP_STRUCT *) a)->sumValue;
}

int stoneGameVI(int* aliceValues, int aliceValuesSize, int* bobValues, int bobValuesSize) {
    int result = 0;
    CMP_STRUCT values[aliceValuesSize];

    for (int i = 0; i < aliceValuesSize; i++) {
      values[i].oriIndex = i;
      values[i].sumValue = aliceValues[i] + bobValues[i];
    }

    qsort (values, aliceValuesSize, sizeof (CMP_STRUCT), cmp);

    for (int i = 0; i < aliceValuesSize; i++) {
      if (i & 1) {
        result -= bobValues[values[i].oriIndex];
      } else {
        result += aliceValues[values[i].oriIndex];
      }
    }

    return result > 0 ? 1 : result == 0 ? 0 : -1;
}

int main () {
  int aliceValues[] = {2,4,3};
  int bobValues[] = {1,6,7};

  printf ("output = %d\n", stoneGameVI (aliceValues, sizeof (aliceValues) / sizeof (aliceValues[0]), bobValues, sizeof (bobValues)/ sizeof (bobValues[0])));
  return 0;
}