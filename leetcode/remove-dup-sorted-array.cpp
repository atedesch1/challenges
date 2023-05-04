#include <vector>

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        int insertionIndex = 0;
        int currentNumber = nums[0];
        for (auto& num : nums) {
            if (num != currentNumber) {
                nums[insertionIndex++] = currentNumber;
                currentNumber = num;
            }
        }
        nums[insertionIndex++] = currentNumber;
        return insertionIndex;
    }
};
