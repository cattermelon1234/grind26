#include <vector>

using namespace std;
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            for (char c : std::to_string(nums[i])) {
                result.push_back(c - '0');
            }
        } 
        return result;
    }
};
