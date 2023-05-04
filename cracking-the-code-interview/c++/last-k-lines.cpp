#include <fstream>
#include <iostream>
#include <string>

void PrintLastKLines(const char* filename, int k) {
    if (k == 0) return;
    auto lines = new std::string[k];
    int start = 0, end = 0;

    std::ifstream file(filename);
    std::string line;

    bool isFirstLine = true;
    while (std::getline(file, line)) {
        if (isFirstLine) {
            lines[end] = line;
            isFirstLine = false;
        } else {
            end = (end + 1) % k;
            lines[end] = line;
            if (end == start) {
                start = (start + 1) % k;
            }
        }
    }

    while (start != end) {
        std::cout << lines[start] << std::endl;
        start = (start + 1) % k;
    }
    std::cout << lines[start] << std::endl;
}

int main() { PrintLastKLines("./test.txt", 21); }
