#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
  static bool isUnique(std::string s)
  {
    auto exists = std::vector<bool>('z' - 'a' + 1);
    for (char &c: s)
    {
      if (exists[c - 'a'])
        return false;
      exists[c - 'a'] = true;
    }
    return true;
  }
};



int main()
{
  std::cout << Solution::isUnique("");
  return 0;
}
