#include <unordered_map>
#include <string>
#include <iostream>

class Solution {
   public:
    int firstUniqChar(std::string s) {
        auto count = std::unordered_map<char, int>();

        for (auto&c: s) {
            count[c]++;
        }

        for(int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) return i;
        }

        return - 1;
    }
};

int main() {
    std::cout << Solution().firstUniqChar("leetcode");
}
