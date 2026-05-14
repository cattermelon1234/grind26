#include <vector>

using namespace std;
class Solution {
public:
  bool isGood(vector<int> &nums) {
    int seen_n = 0;
    int count = 0;
    int n = nums.size();
    std::vector<int> map(n, -1);

    for (int i = 0; i < n; ++i) {
      if (nums[i] >= n || nums[i] <= 0) {
        return false;
      } else if (map[nums[i]] == -1 || (nums[i] == n - 1 && seen_n == 1)) {
        if (nums[i] == n - 1) {
          seen_n += 1;
        }
        map[nums[i]] = 1;
        count += 1;
      } else {
        return false;
      }
    }
    if (count == n) {
      return true;
    }
    return false;
  }
};
