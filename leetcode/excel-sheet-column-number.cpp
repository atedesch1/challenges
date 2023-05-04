#include <iostream>
#include <cmath>
#include <string>

class Solution {
   public:
    int titleToNumber(std::string columnTitle) {
        int number = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            number *= 26;
            number += columnTitle[i] - 'A' + 1;
        }
        return number;
    }
};

int main() {
    std::cout << Solution().titleToNumber("AB");
}
