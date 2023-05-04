#include <vector>

class Solution {
   public:
    void rotate(std::vector<int>& nums, int k) {
        int numMoving = nums[0];
        auto hasMoved = std::vector<bool>(nums.size(), false);
        for (int i = 0, m = 0; i < nums.size(); i++) {
            hasMoved[m] = true;
            m = (m + k) % nums.size();

            if (hasMoved[m]) {
                nums[m] = numMoving;
                for (int i = 0; i < nums.size(); i++) {
                    m = (m + 1) % nums.size();
                    if (!hasMoved[m]) break;
                }
                numMoving = nums[m];
                continue;
            }

            int temp = nums[m];
            nums[m] = numMoving;
            numMoving = temp;
        }
    }
};
