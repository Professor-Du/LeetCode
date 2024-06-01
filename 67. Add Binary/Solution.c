#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int  len_a, len_b, len_s, index, carry;
    char *s    = NULL;

    len_a = strlen (a);
    len_b = strlen (b);

    len_s = ((len_b > len_a) ? len_b : len_a) + 1;
    s = (char *) malloc (sizeof (char) * len_s + 1);
    s[len_s] = '\0';

    for (index = 0, carry = 0; (index < len_s - 1) || (carry != 0); index++, carry >>= 1) {
        carry += ((index < len_a) && (a[len_a - 1 - index] == '1')) ? 1 : 0;
        carry += ((index < len_b) && (b[len_b - 1 - index] == '1')) ? 1 : 0;
        s[len_s - 1 - index] = ((carry & 1) == 0) ? '0' : '1';
    }
    return s + len_s - index;
}

int main () {
    // char *a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    // char *b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

    char *a = "10";
    char *b = "1101";

    // char *a = "1000";
    // char *b = "1101";

    char *s = NULL;

    s = addBinary (a, b);
    printf ("%s", s);

    return 0;
}