#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        int sell = prices.size() - 1;

        for (int buy = sell - 1; buy >= 0; buy--) {
            if (prices[buy] > prices[sell]) {
                sell = buy;
                continue;
            }

            int currentProfit = prices[sell] - prices[buy];
            if (currentProfit > 0) {
                profit += currentProfit;
                sell = buy;
            }
        }
        return profit;
    }
};

int main() {
    auto v = std::vector<int>({1, 2, 3, 4, 5});
    std::cout << Solution().maxProfit(v);
}
