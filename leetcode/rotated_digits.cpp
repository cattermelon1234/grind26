#include <iostream>
#include <vector>

class Solution {
public:
  // if it has 2, 5, 6, 9 and no 3, 4, 7
  int rotatedDigits(int n) {
    // invalid = 0
    // non-unique = 1
    // valid = 2
    std::vector<int> dp(n + 1);
    int valid = 0;
    for (int i = 1; i <= n; ++i) {
      if (i < 10) {
        if (i == 2 || i == 5 || i == 6 || i == 9) {
          dp[i] = 2;
          valid++;
        } else if (i == 3 || i == 4 || i == 7) {
          dp[i] = 0;
        } else {
          dp[i] = 1;
        }
      } else {
        int shifted = (i / 10);
        int new_dig = i % 10;
        if (dp[shifted] == 0) {
          dp[i] = 0;
        } else if (dp[shifted] == 1) {
          if (new_dig == 2 || new_dig == 5 || new_dig == 6 || new_dig == 9) {
            valid++;
            dp[i] = 2;
          } else if (new_dig == 0 || new_dig == 1 || new_dig == 8) {
            dp[i] = 1;
          } else {
            dp[i] = 0;
          }
        } else {
          if (new_dig != 3 && new_dig != 4 && new_dig != 7) {
            valid++;
            dp[i] = 2;
          } else {
            dp[i] = 0;
          }
        }
      }
    }
    return valid;
  }
};
