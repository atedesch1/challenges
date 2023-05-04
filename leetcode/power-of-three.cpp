#include <iostream>

class Solution {
   public:
    bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }
};

int main() { std::cout << Solution().isPowerOfThree(1162261467) << std::endl; }
