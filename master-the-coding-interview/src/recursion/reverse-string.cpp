#include <iostream>
#include <string>

std::string ReverseString(std::string str) {
    if (str.size() <= 1) return str;

    return str.back() + ReverseString(str.substr(0, str.size() - 1));
}

int main() { std::cout << ReverseString("hello") << std::endl; }
