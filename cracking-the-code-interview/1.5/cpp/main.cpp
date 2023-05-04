#include <iostream>
#include <string>

bool isOneAway(std::string s1, std::string s2)
{
  if (abs(s1.length() - s2.length()) > 1)
    return false;

  bool isOneAway = false;

  for (int i = 0, j = 0; i < s1.length() && j < s2.length();)
  {
    if (s1[i] != s2[j])
    {
      if (isOneAway)
        return false;

      if (s1.length() >= s2.length())
      {
        ++i;
      }
      if (s1.length() <= s2.length())
      {
        ++j;
      }
      isOneAway = true;
    }
    else
    {
      ++i;
      ++j;
    }
  }

  return true;
}

int main()
{
  std::cout << isOneAway("pale", "bale") << std::endl;
  return 0;
}
