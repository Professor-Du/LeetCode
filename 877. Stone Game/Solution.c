#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool stoneGame_temp(int* piles, int pilesSize) {  // Doesn't work when piles = [3,7,2,3]
    int output = 0;
    bool AliceTurn = true;

    for (int i = 0, j = pilesSize - 1; i <= j;) {
        int max_num = 0;

        if (piles[i] >= piles[j]) {
            max_num = piles[i];
            i++;
        } else {
            max_num = piles[j];
            j--;
        }

        output += AliceTurn ? max_num : -max_num;
        AliceTurn = !AliceTurn;
    }

    return output > 0;
}


bool stoneGame_dp1(int* piles, int pilesSize) {
    int dp[pilesSize];

    for (int i = 0; i < pilesSize; i++) {
        dp[i] = piles[i];
    }

    for (int i = pilesSize - 2; i >= 0; i--) {  // dp[i][j] = dp[i+1][j] + dp[i][j-1]; check 119. Pascal's Triangle II
        for (int j = i + 1; j < pilesSize; j++) {
            dp[j] = fmax (piles[i] - dp[j], piles[j] - dp[j-1]);
        }
    }

    return dp[pilesSize - 1] > 0;
}

bool stoneGame_dp2(int* piles, int pilesSize) {
    int dp[pilesSize][pilesSize];

    for (int i = 0; i < pilesSize; i++) {
        dp[i][i] = piles[i];
    }

    for (int i = pilesSize - 2; i >= 0; i--) {
        for (int j = i + 1; j < pilesSize; j++) {
            dp[i][j] = fmax (piles[i] - dp[i + 1][j], piles[j] - dp[i][j-1]);
        }
    }

    return dp[0][pilesSize - 1] > 0;
}


bool stoneGame(int* piles, int pilesSize) {
    return true;
}


int main () {
  return 0;
}
