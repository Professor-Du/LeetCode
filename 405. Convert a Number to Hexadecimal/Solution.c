char digit2Hex (unsigned int num) {
    if (num < 10) {
        return num + '0';
    }
    return num - 10 + 'a';
}

char * toHex(int num){  // Faster than 100% solutions!!!
    unsigned int i = 9, x = (unsigned int) num;
    char *hexStr = malloc (sizeof (char) * i);

    hexStr[--i] = '\0';
    do {
        hexStr[--i] = digit2Hex (x % 16);
        x /= 16;
    } while (x > 0);

    return hexStr + i;
}