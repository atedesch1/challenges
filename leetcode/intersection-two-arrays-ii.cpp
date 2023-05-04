#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> intersect(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);

        auto map = std::unordered_map<int, int>();
        for (auto& num : nums1) {
            map[num]++;
        }

        auto intersection = std::vector<int>();
        for (auto& num : nums2) {
            auto it = map.find(num);
            if (it != map.end() && it->second > 0) {
                intersection.push_back(num);
                it->second--;
            }
        }
        return intersection;
    }
};
