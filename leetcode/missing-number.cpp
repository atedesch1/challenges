#include <vector>

class Solution {
   public:
    int missingNumber(std::vector<int>& nums) {
        int sum = 0;
        int size = nums.size();

        for (auto& num : nums) {
            sum += num;
        }

        return size * (size + 1.) / 2. - sum;


    }
};
