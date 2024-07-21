bool isSymmetric (int n) {
    int top = 0, *stack = malloc (sizeof (int) * 6);

    stack[0] = 0;
    while (n > 0) {
        top++;
        stack[top] = stack[top - 1] + (n % 10);
        n /= 10;
    }

    return ((top % 2) == 0) && (stack[top] == 2 * stack[top/2]);
}

int countSymmetricIntegers(int low, int high){
    int cnt = 0;
    for (int i = low; i <= high; i++) {
        if (isSymmetric (i)) {
            cnt++;
        }
    }

    return cnt;
}