int climbStairs(int n) {  // Faster than 100% solutions!!!
    if (n == 1) {
        return 1;  // Not really needed - For speeding up only
    }
    int *a = malloc (sizeof (int) * n);
    a[0] = 1; a[1] = 2;
    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n - 1];
}