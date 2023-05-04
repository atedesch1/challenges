#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> fizzBuzz(int n) {
        auto answer = std::vector<std::string>(n);

        for (int i = 0; i < n; i++) {
            int oneIndex = i + 1;

            if (oneIndex % 15 == 0) {
                answer[i] = std::string("FizzBuzz");
            } else if (oneIndex % 3 == 0) {
                answer[i] = std::string("Fizz");
                continue;
            } else if (oneIndex % 5 == 0) {
                answer[i] = std::string("Buzz");
                continue;
            } else {
                answer[i] = std::to_string(oneIndex);
            }
        }
        return answer;
    }
};

int main() {
    auto fB = Solution().fizzBuzz(10000);
    for (auto &s : fB) {
        std::cout << s << std::endl;
    }
}
