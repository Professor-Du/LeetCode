bool isPowerOfTwo(int n) {  // Faster than 100% solutions!!!
    return ((n > 0) && (n & (n-1)) == 0);
}