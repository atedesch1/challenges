#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int rob(std::vector<int>& nums) {
        auto cache = std::vector<int>(nums.size(), -1);
        return robRecursive(nums, cache, 0);
    }

    int robRecursive(std::vector<int>& nums, std::vector<int>& cache,
                     int pick) {
        int maxAdjacent = 0, maxNonAdjacent = 0;

        if (pick + 1 < nums.size()) {
            cache[pick + 1] = cache[pick + 1] < 0
                                  ? robRecursive(nums, cache, pick + 1)
                                  : cache[pick + 1];
            maxAdjacent = cache[pick + 1];
        }
        if (pick + 2 < nums.size()) {
            cache[pick + 2] = cache[pick + 2] < 0
                                  ? robRecursive(nums, cache, pick + 2)
                                  : cache[pick + 2];
            maxNonAdjacent = cache[pick + 2];
        }

        return std::max(maxAdjacent, nums[pick] + maxNonAdjacent);
    }

    int robIterative(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        auto cache = std::vector<int>(nums.size() + 1);

        cache[0] = 0;
        cache[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cache[i + 1] = std::max(cache[i], cache[i - 1] + nums[i]);
        }

        return cache[nums.size()];
    }
};

int main() {
    auto v = std::vector<int>({2, 7, 9, 3, 1});
    std::cout << Solution().robIterative(v);
}
