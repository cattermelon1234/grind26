#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[left] < nums[right]) {
        return nums[left];
      }
      if (right - left <= 1) {
        return std::min(nums[left], nums[right]);
      }
      // otherwise case 1: move right
      if (nums[mid] > nums[right]) {
        left = mid;
      }
      // move left
      else {
        right = mid;
      }
    }
    return nums[left];
  }
};
