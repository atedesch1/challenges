#include <string>

class Solution {
   public:
    int strStr(std::string haystack, std::string needle) {
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        if (needleSize > haystackSize) return -1;

        for (int i = 0; i < haystackSize - needleSize + 1; i++) {
            for (int j = 0; j < needleSize; j++) {
                if (haystack[i + j] != needle[j]) break;
                if (j == needleSize - 1) return i;
            }
        }

        return -1;
    }
};
