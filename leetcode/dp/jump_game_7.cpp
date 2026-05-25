#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    std::vector<int> dp(n, 0);
    int reachable = 0;
    dp[n - 1] = 1;
    if (s[n - 1] == '1') {
      return false;
    }
    for (int i = n - 2; i >= 0; --i) {
      int low = i + minJump;
      int high = i + maxJump + 1;
      if (high <= n - 1 && dp[high] == 1) {
        reachable--;
      }
      if (low <= n - 1 && dp[low] == 1) {
        reachable++;
      }
      dp[i] = (reachable > 0) && s[i] == '0';
    }
    return dp[0];
  }
};
