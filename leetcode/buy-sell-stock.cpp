#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int buy = prices[prices.size() - 1];
        int sell = buy;
        int maximumProfit = sell - buy;

        for (int i = prices.size() - 2; i >= 0; i--) {
            buy = prices[i];
            sell = std::max(sell, prices[i + 1]);
            maximumProfit = std::max(maximumProfit, sell - buy);
        }

        return maximumProfit;
    }
};
