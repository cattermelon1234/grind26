#include <iostream>
#include <vector>

class Solution {
public:
  int maxRotateFunction(std::vector<int> &nums) {
    int sum = 0;
    int max = std::numeric_limits<int>::min();
    int f = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      f += nums[i] * i;
    }
    max = f;
    // rotation
    for (int i = 1; i < n; ++i) {
      f += sum;
      f -= n * nums[n - i];
      max = std::max(max, f);
    }
    return max;
  }
};
