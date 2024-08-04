int minimumBuckets(char* hamsters) {  // Faster than 100% solutions!!!
    int i, cnt = 0, n = strlen (hamsters);
    for (i = 0; i < n; i++) {
        if (hamsters[i] == 'H') {
            if (i + 1 >= n || hamsters[i + 1] == 'H') {  // Cannot place food bucket on right
                if (i == 0 || hamsters[i - 1] == 'H') {
                    return -1;  // Cannot place food bucket on left
                }
                cnt++;  // Place food bucket on left
            } else {
                cnt++;  // Place food bucket on right
                i += 2; // Skip next two indices (i+1: food bucket, i+2: empty or hamster sharing food bucket on i+1)
            }
        }
    }

    return cnt;
}