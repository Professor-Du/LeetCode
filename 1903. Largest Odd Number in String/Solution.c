char* largestOddNumber(char* num) {
    int i;

    for (i = strlen (num) - 1; i >= 0; i--) {
        if ((num[i] - '0') & 1) {
            break;
        }
    }

    num[i + 1] = '\0';

    return num;
}

char* largestOddNumber_better(char* num) {
    int i;

    for (i = strlen (num) - 1; i >= 0; i--) {
        if ((num[i] - '0') & 1) {
            num[i + 1] = '\0';
            return num;
        }
    }

    return "";
}