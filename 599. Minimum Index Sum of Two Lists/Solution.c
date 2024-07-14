#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <uthash.h>  // unstandard library

#define INT_MAX         __INT_MAX__
#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

typedef struct {
    char  *key;
    int   val;
    UT_hash_handle  hh;
} HASH_TABLE;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int sum, pos = 0, leastIndex = INT_MAX;
    char **result = malloc (sizeof (char *) * fmin (list1Size, list2Size));
    HASH_TABLE *hashEntry, *hashTable = NULL;

    for (int i = 0; i < list1Size; i++) {
        hashEntry = malloc (sizeof (HASH_TABLE));
        hashEntry->key = list1[i];
        hashEntry->val = i;
        HASH_ADD_STR (hashTable, key, hashEntry);
    }

    for (int i = 0; i < list2Size; i++) {
        HASH_FIND_STR (hashTable, list2[i], hashEntry);
        if (hashEntry == NULL) {
            continue;
        }

        sum = hashEntry->val + i;
        if (sum > leastIndex) {
            continue;
        }

        if (sum < leastIndex) {
            leastIndex = sum;
            pos = 0;  // clever
        }
        result[pos++] = hashEntry->key;
    }

    *returnSize = pos;
    return result;
}

char** findRestaurant_clever(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    if (list1Size > list2Size) {
      findRestaurant_clever (list2, list2Size, list1, list1Size, returnSize);  // clever
    }

    int sum, pos = 0, leastIndex = INT_MAX;
    char **result = malloc (sizeof (char *) * fmin (list1Size, list2Size));
    HASH_TABLE *hashEntry, *hashTable = NULL;

    for (int i = 0; i < list1Size; i++) {
        hashEntry = malloc (sizeof (HASH_TABLE));
        hashEntry->key = list1[i];
        hashEntry->val = i;
        HASH_ADD_STR (hashTable, key, hashEntry);
    }

    for (int i = 0; i < list2Size; i++) {
        HASH_FIND_STR (hashTable, list2[i], hashEntry);
        if (hashEntry == NULL) {
            continue;
        }

        sum = hashEntry->val + i;
        if (sum > leastIndex) {
            continue;
        }

        if (sum < leastIndex) {
            leastIndex = sum;
            pos = 0;
        }
        result[pos++] = hashEntry->key;
    }

    *returnSize = pos;
    return result;
}

int main () {
  char *list1[] = {"Shogun","Tapioca Express","Burger King","KFC"};
  char *list2[] = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

  printf ("input: list1 = ");
  for (int i = 0; i < ARRAY_SIZE (list1); i++) {
    printf ("'%s' ", list1[i]);
  }

  printf ("list2 = ");
  for (int i = 0; i < ARRAY_SIZE (list2); i++) {
    printf ("'%s' ", list2[i]);
  }

  printf (" output: ");
  int returnSize;
  char **s = findRestaurant_clever (list1, ARRAY_SIZE (list1), list2, ARRAY_SIZE (list2), &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf ("'%s' ", s[i]);
  }

  getchar ();
  return 0;
}