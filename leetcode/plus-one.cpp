#include <iostream>
#include <ostream>
#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] > 0) break;
        }

        if (digits[0] == 0) {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};

int main() {
    auto v = std::vector<int>({9, 9, 9});
    for (auto& i : Solution().plusOne(v)) {
        std::cout << i;
    }
    std::cout << std::endl;
}
