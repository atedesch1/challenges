#include <vector>

class Solution {
   public:
    void moveZeroes(std::vector<int>& nums) {
        int insertionIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num != 0) {
                if (insertionIndex < i) nums[insertionIndex] = num;
                insertionIndex++;
            }
        }
        std::fill(nums.begin() + insertionIndex, nums.end(), 0);
    }
};
