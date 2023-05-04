#include <iostream>
#include <string>

void appendCharCompression(std::string &s, char c, u_int n)
{
  s.append(std::string(1, c));
  s.append(std::to_string(n));
}

std::string stringCompression(std::string s)
{
  u_int counter = 0;
  char curr = s.at(0);
  std::string compressed;

  for (char &c : s)
  {
    if (c != curr)
    {
      appendCharCompression(compressed, curr, counter);
      counter = 0;
      curr = c;
    }
    counter++;
  }

  appendCharCompression(compressed, curr, counter);

  return compressed.length() < s.length() ? compressed : s;
}

int main()
{
  std::cout << stringCompression("aaaabbbcccccaa") << std::endl;
  return 0;
}
