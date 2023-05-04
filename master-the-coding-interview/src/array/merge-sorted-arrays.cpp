#include <iostream>
#include <vector>

std::vector<int> MergeSortedArrays(std::vector<int> v, std::vector<int> w) {
    auto mergedArrays = std::vector<int>(v.size() + w.size());
    int i = 0;
    auto vIterator = v.begin();
    auto wIterator = w.begin();

    while (vIterator != v.end() || wIterator != w.end()) {
        if (wIterator == w.end() ||
            (vIterator != v.end() && *vIterator <= *wIterator)) {
            mergedArrays[i] = *vIterator;
            vIterator++;
        } else {
            mergedArrays[i] = *wIterator;
            wIterator++;
        }
        i++;
    }

    return mergedArrays;
}

int main() {
    auto v = std::vector<int>({1, 2, 3, 4});
    auto w = std::vector<int>({3, 5, 9, 10});
    auto mergedArray = MergeSortedArrays(v, w);

    for (auto& val : mergedArray) {
        std::cout << val << " ,";
    }
    std::cout << "\n";
}
