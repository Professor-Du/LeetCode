int thirdMax(int* nums, int numsSize){
  int i, j, flag, max[3] = {INT_MAX};

  for (i = 0; i < 3; i++) {
    max[i] = INT_MIN;
    for (j = 0, flag = 0; j < numsSize; j++) {
      if (i == 0 || nums[j] < max[i-1]) {
        max[i] = fmax (max[i], nums[j]);
        flag = 1;
      }
    }
    if (flag == 0) {
      return max[0];
    }
  }

  return max[2];
}