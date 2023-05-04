#include <vector>

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        auto cache = std::vector<int>(n, -1);
        return climbStairsRecursive(n, cache);
    }

    int climbStairsRecursive(int n, std::vector<int>& cache) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (cache[n - 1] < 0) {
            cache[n - 1] = climbStairsRecursive(n - 1, cache);
        }
        if (cache[n - 2] < 0) {
            cache[n - 2] = climbStairsRecursive(n - 2, cache);
        }

        return cache[n - 1] + cache[n - 2];
    }
};
