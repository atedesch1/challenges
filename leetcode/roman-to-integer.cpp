#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<char, int> romanValue;

   public:
    Solution() {
        romanValue['I'] = 1;
        romanValue['V'] = 5;
        romanValue['X'] = 10;
        romanValue['L'] = 50;
        romanValue['C'] = 100;
        romanValue['D'] = 500;
        romanValue['M'] = 1000;
    }

    int romanToInt(std::string s) {
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && romanValue[s[i]] < romanValue[s[i + 1]]) {
                answer -= romanValue[s[i]];
            } else {
                answer += romanValue[s[i]];
            }
        }

        return answer;
    }
};

int main() { std::cout << Solution().romanToInt("MCMXCIV"); }
