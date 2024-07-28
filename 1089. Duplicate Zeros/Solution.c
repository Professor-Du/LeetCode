void duplicateZeros(int* arr, int arrSize) {
  int i, cnt = 0;
  for (i = 0; i < arrSize; i++) {
    if (arr[i] == 0) {
      cnt++;
    }
  }

  for (i = arrSize - 1; i >= 0; i--) {
    if (arr[i] == 0) {
      if (i + cnt < arrSize) {
        arr[i + cnt] = 0;
      }
      cnt--;
      if (i + cnt < arrSize) {
        arr[i + cnt] = 0;
      }
    } if (i + cnt < arrSize) {
      arr[i + cnt] = arr[i];
    }
  }
}