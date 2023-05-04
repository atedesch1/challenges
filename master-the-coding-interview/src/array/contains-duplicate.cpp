#include <vector>
#include <unordered_set>

class Solution {
   public:
       bool containsDuplicate(std::vector<int>& nums) {
           auto contains = std::unordered_set<int>();
           for (auto &num: nums) {
               auto it = contains.find(num);
               if (it != contains.end()) {
                   return true;
               }
               contains.insert(num);
           }
           return false;
       }
};
