struct hashStruct {
  int key;
  int val;
  UT_hash_handle hh;
};

int tupleSameProduct_hash(int* nums, int numsSize) {
  int i, j, prod, cnt = 0;
  struct hashStruct *p, *hashHead = NULL;

  for (i = 0; i < numsSize; i++) {
    for (j = i + 1; j < numsSize; j++) {
      p = NULL;
      prod = nums[i] * nums[j];
      HASH_FIND_INT (hashHead, &prod, p);

      if (p != NULL) {
        p->val++;
      } else {
        p = malloc (sizeof (struct hashStruct));
        p->key = prod;
        p->val = 1;
        HASH_ADD_INT (hashHead, key, p);
      }
    }
  }

  for (p = hashHead; p != NULL; p = p->hh.next) {
    cnt += p->val * (p->val - 1) * 4;
  }

  return cnt;
}


static int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int tupleSameProduct(int* nums, int numsSize) {  // Faster than 100% solutions!!!
  int i, j, n = 0, cnt = 0, prods[(numsSize * (numsSize - 1)) / 2];

  for (i = 0; i < numsSize; i++) {
    for (j = i + 1; j < numsSize; j++) {
      prods[cnt++] = nums[i] * nums[j];
    }
  }

  qsort(prods, cnt, sizeof (int), cmp);

  for (i = 1; i < cnt; i++) {
    for (j = i - 1; prods[j] == prods[i]; j--) {
      n++;
    }
  }

  // for (i = 1; i < cnt; i++) {  // timeout
  //   for (j = i + 1; j < cnt; j++) {
  //     if (prods[i] == prods[j]) {
  //       n++;
  //     }
  //   }
  // }

  return n * 8;
}