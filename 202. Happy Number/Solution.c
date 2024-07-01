#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int happySum(int n) {
  int sum;

  for (sum = 0; n > 0; n /= 10) {
    sum += (int) pow (n % 10, 2);
  }

  return sum;
}

bool isHappy(int n) {  // Faster than 100% solutions!!!
  int slow = n, fast = happySum(n);

  while ((fast != 1) && (fast != slow)) {
    slow = happySum(slow);
    fast = happySum(happySum(fast));
  }

  return fast == 1;
}

int main () {
  int n = 19;  // 2

  printf ("input: %d  output: %s\n", n, isHappy (n) ? "true" : "false");

  getchar ();
  return 0;
}