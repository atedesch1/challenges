#include <string>

class Solution {
   public:
    bool isPalindrome(std::string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char leftChar = toLowerCase(s[l]);
            char rightChar = toLowerCase(s[r]);

            if (!isValidCharacter(leftChar))
                l++;
            else if (!isValidCharacter(rightChar))
                r--;
            else if (leftChar != rightChar)
                return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }

    bool isValidCharacter(char c) {
        return ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
    }

    char toLowerCase(char c) {
        return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
    }
};
