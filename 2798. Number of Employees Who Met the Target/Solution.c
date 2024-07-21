int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target){  // Faster than 100% solutions!!!
    int i, cnt = 0;
    for (i = 0; i < hoursSize; i++) {
        if (hours[i] >= target) {
            cnt++;
        }
    }

    return cnt;
}