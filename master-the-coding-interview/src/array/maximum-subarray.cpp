#include <limits.h>

#include <algorithm>
#include <vector>

class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        auto dp = std::vector<int>(nums.size(), INT_MIN);
        return solveDP(nums, dp, 0, false);
    }

    int solveRecursive(std::vector<int>& nums, int idx, bool pick) {
        if (idx > nums.size() - 1) return pick ? 0 : INT_MIN;
        if (pick) {
            return std::max(0, nums[idx] + solveRecursive(nums, idx + 1, true));
        }
        return std::max(solveRecursive(nums, idx + 1, false),
                        nums[idx] + solveRecursive(nums, idx + 1, true));
    }

    int solveDP(std::vector<int>& nums, std::vector<int>& dp, int idx,
                bool pick) {
        if (idx > nums.size() - 1) return pick ? 0 : INT_MIN;
        if (pick) {
            if (dp[idx] > INT_MIN) return dp[idx];
            dp[idx] =
                std::max(0, nums[idx] + solveDP(nums, dp, idx + 1, true));
            return dp[idx];
        }
        return std::max(solveDP(nums, dp, idx + 1, false),
                        nums[idx] + solveDP(nums, dp, idx + 1, true));
    }

    int solveKadane(std::vector<int>& nums) {
        int currentMax = 0, max = INT_MIN;
        for (auto& num: nums) {
            currentMax = std::max(num, currentMax + num);
            max = std::max(max, currentMax);
        }
        return max;
    }
};
