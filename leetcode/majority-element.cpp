#include <unordered_map>
#include <vector>

class Solution {
   public:
    int majorityElement(std::vector<int>& nums) {
        auto map = std::unordered_map<int, int>();
        for (auto& num : nums) {
            if (map.find(num) == map.end()) {
                map[num] = 1;
            } else {
                map[num] += 1;
            }

            if (map[num] > (int)(nums.size() / 2)) {
                return num;
            }
        }

        throw "Wrong parameters";
    }

    int majorityElementFaster(std::vector<int>& nums) {
        int curr;
        for (int i = 0, count = 0; i < nums.size(); i++) {
            if (count == 0) curr = nums[i];
            count += curr == nums[i] ? 1 : -1;
        }

        return curr;
    }
};
