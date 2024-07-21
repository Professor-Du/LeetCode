int sumBase(int n, int k) {  // Faster than 100% solutions!!!
    int sum = 0;
    while (n > 0) {
        sum += n % k;
        n/= k;
    }

    return sum;
}