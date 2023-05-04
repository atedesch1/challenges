#include <iostream>
#include <string>

class Solution {
   public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";
        auto prev = countAndSay(n - 1);
        char currChar = prev[0];
        int count = 0;
        std::string s;
        for (auto& c : prev) {
            if (c != currChar) {
                s += std::to_string(count) + currChar;
                currChar = c;
                count = 0;
            }
            count++;
        }
        s += std::to_string(count) + currChar;
        return s;
    }
};

int main() { std::cout << Solution().countAndSay(4) << std::endl; }
