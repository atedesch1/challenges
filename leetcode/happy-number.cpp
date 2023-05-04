#include <unordered_set>
class Solution {
   public:
    bool isHappy(int n) {
        auto set = std::unordered_set<int>();

        int result = n;
        int num = n;
        while (result != 1) {
            set.insert(result);
            result = 0;
            while (num > 0) {
                int digit = num % 10;
                result += digit * digit;
                num /= 10;
            }
            if (set.find(result) != set.end()) return false;
            num = result;
        }
        return true;
    }
};
