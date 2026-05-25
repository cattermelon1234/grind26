#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  bool check(vector<int> &nums) {
    int smallest = nums[0];
    int n = nums.size();
    bool pivot = false;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1]) {
        if (!pivot && nums[i] <= smallest) {
          pivot = true;
        } else {
          return false;
        }
      } else {
        if (nums[i] > smallest && pivot) {
          return false;
        }
      }
    }
    return true;
  }
};
