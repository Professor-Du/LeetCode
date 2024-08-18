bool isThree(int n) {  // Faster then 100% solutions!!!
  int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};  // exclude 1
  int temp, mid, left = 0, right = 24;

  do {
    mid = (left + right) / 2;
    temp = prime[mid] * prime[mid];
    if (n == temp) {
      return true;
    } else if (n < temp) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  } while (left <= right);

  return false;
}