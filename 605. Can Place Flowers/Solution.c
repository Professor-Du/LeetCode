bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
  if (n == 0) {
    return true;
  }
  int cnt = 0;
  for (int i = 0; i < flowerbedSize; i++) {
    if (flowerbed[i] == 1) {
      i++;
      continue;
    }
    if (i - 1 >= 0 && flowerbed[i - 1] == 1) {
      continue;
    }
    if (i + 1 < flowerbedSize && flowerbed[i + 1] == 1) {
      i += 2;
      continue;
    }
    flowerbed[i++] = 1;
    if (++cnt >= n) {
      return true;
    }
  }
  return false;
}