#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof (arr[0]))

int majorityElement_0(int* nums, int numsSize) {  // Hash in bitmap level
  int temp, bitmap[32] = {0};
  for (int i = 0; i < numsSize; i++) {
    temp = nums[i];
    for (int j = 0; j < 32; j++) {
      bitmap[j] += temp & 1;
      temp >>= 1;
    }
  }

  unsigned int s = 0;
  for (int j = 31; j >= 0; j--) {
    s = (s << 1) + (bitmap[j] * 2 > numsSize);
  }

  return (int) s;
}

static int cmp (const void *a, const void *b) {
  return *((int *) a) - *((int *) b);
}

int majorityElement_1(int* nums, int numsSize) {  // quick sort
  qsort (nums, numsSize, sizeof (int), cmp);

  for (int i = 1, cnt = 1; i < numsSize; i++) {
    if (nums[i] != nums[i - 1]) {
      cnt = 1;
    } else if ((++cnt) * 2 > numsSize ) {
      return nums[i];
    }
  }

  return nums[0];  // consider len = 1
}

int majorityElement_2_0(int* nums, int numsSize) {  // Boyer-Moore algorithm v0
  int candidate;

  for (int i = 0, cnt = 0; i < numsSize; i++) {
    if (cnt == 0) {
      candidate = nums[i];
      cnt++;
    } else if (nums[i] != candidate) {
      cnt--;
    } else if ((++cnt) * 2 > numsSize ) {
      return candidate;
    }
  }

  return candidate;
}

int majorityElement_2_1(int* nums, int numsSize) {  // Boyer-Moore algorithm v1
  int candidate;

  for (int i = 0, cnt = 0; i < numsSize; i++) {
    if (cnt == 0) {
      candidate = nums[i];
    }

    cnt += (nums[i] == candidate) ? 1 : -1;
  }

  return candidate;
}

int main () {
  int a[] = {2,2,1,1,1,2,2};

  printf ("input: ");
  for (int i = 0; i < ARRAY_SIZE (a); i++) {
    printf ("%d ", a[i]);
  }

  printf (" output: %d\n", majorityElement_1 (a, ARRAY_SIZE(a)));

  getchar ();
  return 0;
}