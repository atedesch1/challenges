#include <stack>
#include <string>

class Solution {
   public:
    bool isValid(std::string s) {
        auto stack = std::stack<char>();
        for (auto& c : s) {
            switch (c) {
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                default:
                    if (stack.empty() || c != stack.top()) return false;
                    stack.pop();
                    break;
            }
        }
        return stack.empty();
    }
};
