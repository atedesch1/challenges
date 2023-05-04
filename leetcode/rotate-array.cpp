#include <iostream>
#include <vector>

class Solution {
   public:
    void rotate(std::vector<int>& nums, int k) {
        if (k % nums.size() == 0) return;
        int numsSize = nums.size();
        int numberOfRotations = 0;
        int startingIndex = 0;
        int currentIndex = 0;
        int temp = nums[startingIndex];

        while (numberOfRotations < numsSize) {
            currentIndex = (currentIndex + k) % numsSize;
            int newTemp = nums[currentIndex];
            nums[currentIndex] = temp;
            temp = newTemp;
            if (currentIndex == startingIndex) {
                startingIndex++;
                currentIndex = startingIndex;
                temp = nums[startingIndex];
            }
            numberOfRotations++;
        }
    }
};

int main() {
    auto vec = std::vector<int>({1, 2, 3, 4});
    Solution().rotate(vec, 2);
    for (auto& num : vec) {
        std::cout << num << " ";
    }
}
