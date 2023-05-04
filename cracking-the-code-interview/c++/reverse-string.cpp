#include <cstring>
#include <iostream>

void Reverse(char* str) {
    int p1 = 0, p2 = 0;
    for (; str[p2 + 1] != '\0'; p2++)
        ;
    while (p2 > p1) {
        char temp = str[p2];
        str[p2] = str[p1];
        str[p1] = temp;
        p1++;
        p2--;
    }
}

int main() {
    char str[] = "ab";
    std::cout << str << std::endl;
    Reverse(str);
    std::cout << str << std::endl;
}
