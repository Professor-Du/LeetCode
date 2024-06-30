#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mPickNum;

void setPickNum (int n) {
  mPickNum = n;
}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess (int n) {
  return n > mPickNum ? -1 : n == mPickNum ? 0 : 1;
}

int guessNumber(int n){
  long long low = 1, high = n, temp = (low + high) / 2;  // sizeof (long) equals to 8 in leetcode but 4 here.

  while (low < high) {
    switch (guess (temp)) {
      case -1: high = temp - 1; break;
      case 1 : low  = temp + 1; break;
      case 0 : return temp;
    }

    temp = (low + high) / 2;
  }

  return temp;
}


int main () {
  int n = 2126753390, pick = 1702766719;

  setPickNum (pick);
  printf("intput: n=%d, pick=%d  output: %s\n", n, pick, guessNumber(n) == pick ? "success" : "failure");

  getchar ();
  return 0;
}