#include <limits.h>

#include <algorithm>
#include <vector>

class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        int currentMax = 0, max = INT_MIN;
        for (auto& num : nums) {
            currentMax = std::max(num, currentMax + max);
            max = std::max(max, currentMax);
        }
        return max;
    }
};
