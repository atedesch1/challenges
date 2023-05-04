#include <vector>

class Solution {
   public:
    void reverseString(std::vector<char>& s) {  
        int midPoint = s.size() / 2;

        for (int i = 0; i < midPoint; i++) {
            int reverseIndex = s.size() - 1 - i;
            char temp = s[reverseIndex];
            s[reverseIndex] = s[i];
            s[i] = temp;
        }
    }
};
