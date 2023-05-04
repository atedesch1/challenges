#include <string>
#include <unordered_map>

class Solution {
   public:
    bool isAnagram(std::string s, std::string t) {
        auto charMap = std::unordered_map<char, int>();

        for (auto& c : s) {
            charMap[c]++;
        }

        for (auto& c : t) {
            if (charMap.find(c) == charMap.end()) {
                return false;
            }
            charMap[c]--;
        }

        for (auto& val : charMap) {
            if (val.second > 0) return false;
        }
        return true;
    }
};
