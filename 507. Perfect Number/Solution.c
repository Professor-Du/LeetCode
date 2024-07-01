#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkPerfectNumber(int num){  // Faster than 100% solutions!!!
    int sum = 0, div = (int) sqrt (num);

    if (num == 1) {
        return false;
    } else if (num == div * div) {
        sum += div;
    } else if ((num % div) == 0) {
        sum += div + num / div;
    }

    for (div -= 1; div > 1; div--) {
        if ((num % div) == 0) {
            sum += div + num / div;
        }
    }

    return num == sum + 1;
}

int main () {
    int num = 28;

    printf ("input: %d  output: %s\n", num, checkPerfectNumber (num) ? "perfect" : "imperfect");

    getchar ();
    return 0;
}
