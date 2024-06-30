#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canWinNim2(int n) {  // timeout when n >= 44
    if (n <= 3) {
        return true;
    }

    for (int i = 1; i <= 3; i++) {
        if (!canWinNim2 (n - i)) {
            return true;
        }
    }

    return false;
}

bool canWinNim(int n) {
    return n % 4;
}

int main () {
  for (int i = 1; i < (1 << 31); i++) {
    if (canWinNim2 (i) != canWinNim (i)) {
      printf ("error when n = %d\n", i);
      return 0;
    }
  }

  printf ("test passed\n");
  return 0;
}
