#include <cmath>
#include <iostream>
#include <list>
#include <vector>

class Solution {
   public:
    int countPrimes(int n) {
        auto primes = std::list<int>();
        int numOfPrimes = 0;
        for (int i = 2; i < n; i++) {
            bool isPrime = true;
            int sqrtI = std::sqrt(i);
            for (auto prime = primes.begin();
                 prime != primes.end() && *prime <= sqrtI; prime++) {
                if (i % *prime == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.push_back(i);
                numOfPrimes++;
            }
        }

        return numOfPrimes;
    }
    int countPrimesImproved(int n) {
        int numOfPrimes = 0;
        std::vector<bool> isPrime(n + 1, true);
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                numOfPrimes++;
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return numOfPrimes;
    }
};

int main() { std::cout << Solution().countPrimesImproved(5000000); }
