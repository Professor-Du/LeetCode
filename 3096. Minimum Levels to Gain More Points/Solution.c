int minimumLevels(int* possible, int possibleSize) {
    int i, sum = 0, alice = 0;
    for (i = 0; i < possibleSize; i++) {
        sum += possible[i];
    }

    sum = sum * 2 - possibleSize;
    sum = (sum < 0) ? (sum - 1) / 2 : sum / 2;

    for (i = 0; i < possibleSize - 1; i++) {
        alice += (possible[i] == 1) ? 1 : -1;
        if (alice > sum) {
            return i + 1;
        }
    }

    return -1;
}