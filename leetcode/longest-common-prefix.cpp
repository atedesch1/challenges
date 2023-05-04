#include <string>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string common;
        int idx = 0;
        while (true) {
            bool isFirst = true;
            char currChar;
            for (auto& str : strs) {
                if (idx >= str.size()) return common;
                if (isFirst) {
                    currChar = str[idx];
                    isFirst = false;
                } else if (str[idx] != currChar) {
                    return common;
                }
            }
            common += currChar;
            idx++;
        }
    }
};
