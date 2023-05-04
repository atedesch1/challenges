#include <vector>
class Solution {
   public:
    int singleNumber(std::vector<int>& nums) {
        int answer = 0;
        for (auto& num : nums) {
            answer ^= num;
        }
        return answer;
    }
};
