#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
  public:
  static bool checkPermutation(std::string a, std::string b)
  {
    if (a.size() != b.size()) return false;
    auto m = std::unordered_map<char, int>();

    for (char &c: a)
    {
      if (m.find(c) != m.end())
        m[c]++;
      else
        m[c] = 1;
    }

    for (char &c: b)
    {
      if (m.find(c) == m.end() || m[c] == 0)
        return false;
      else
        m[c]--;
    }
    return true;
  }
};

int main()
{
  std::cout << Solution::checkPermutation("abcad", "abcad");
  return 0;
}
