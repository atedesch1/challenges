#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> generate(int numRows) {
        auto triangle = std::vector<std::vector<int>>();
        triangle.push_back(std::vector<int>({1}));

        for (int i = 1; i < numRows; i++) {
            auto row = std::vector<int>(i + 1);
            auto precedingRow = triangle[i - 1];
            for (int j = 0; j <= i; j++) {
                int leftNum = j - 1 < 0 ? 0 : precedingRow[j - 1];
                int rightNum =
                    j > precedingRow.size() - 1 ? 0 : precedingRow[j];
                row[j] = leftNum + rightNum;
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};
