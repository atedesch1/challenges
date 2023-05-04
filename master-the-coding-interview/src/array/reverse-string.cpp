#include <string>
#include <iostream>

std::string ReverseString(std::string str) {
    int halfSize = str.size() / 2;

    for (int i = 0; i < halfSize; i++) {
        int temp = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = temp; 
    }

    return str;
}


int main() {
    auto str = std::string("");
    std::cout << ReverseString(str) << std::endl;
}
