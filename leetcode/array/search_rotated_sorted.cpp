#include <vector>

using namespace std;
class Solution {
public:
  int bsearch(int left, int right, vector<int> nums, int target) {
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int sortedLeft;
    int sortedRight;
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] > nums[left] && nums[mid] < nums[right]) {
        return bsearch(left, right, nums, target);
      } else if (nums[mid] > nums[left]) {
        // sortef left
        sortedLeft = left;
        sortedRight = mid;
        left = mid + 1;
      } else {
        sortedLeft = mid + 1;
        sortedRight = right;
        right = mid - 1;
      }
      if (sortedLeft < 0 || sortedRight >= n || sortedLeft >= n) {
        return -1;
      }
      if (nums[sortedLeft] <= target && target <= nums[sortedRight]) {
        return bsearch(sortedLeft, sortedRight, nums, target);
      }
    }
    return -1;
  }
};
