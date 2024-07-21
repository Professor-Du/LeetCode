char * removeTrailingZeros(char * num){
    int i, m;
    for (i = 1, m = 0; num[i] != '\0'; i++) {
        if (num[i] != '0') {
            m = i;
        }
    }
    num[m + 1] = '\0';

    // int i, n = strlen(num);
    // for (i = n - 1; i >= 0; i--) {
    //     if (num[i] != '0') {
    //         break;
    //     }
    //     num[i] = '\0';
    // }
    return num;
}