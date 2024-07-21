char slowestKey(int* releaseTimes, int releaseTimesSize, char* keysPressed) {
    int i, curTime, maxTime = releaseTimes[0];
    char key = keysPressed[0];

    for (i = 1; i < releaseTimesSize; i++) {
        curTime = releaseTimes[i] - releaseTimes[i - 1];
        if ((curTime == maxTime) && keysPressed[i] > key) {
            key = keysPressed[i];
        } else if (curTime > maxTime) {
            key = keysPressed[i];
            maxTime = curTime;
        }
    }

    return key;
}