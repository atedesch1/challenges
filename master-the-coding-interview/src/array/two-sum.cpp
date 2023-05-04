#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        auto map = std::unordered_map<int, int>();

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            auto mapIterator = map.find(complement);

            if (mapIterator != map.end()) {
                return { i, mapIterator->second };
            }

            map[num] = i;
        }

        return {};
    }
};
