#include <iostream>
#include <vector>

std::vector<int> Merge(std::vector<int>& v, int l, int r) {
    if (l == r) return {l, r};
    int m = (l + r) / 2;

    auto vl = Merge(v, l, m);
    auto vr = Merge(v, m + 1, r);

    auto pl = vl[0];
    auto pr = vr[0];

    auto vn = std::vector<int>(vr[1] - vl[0] + 1);
    for (int i = 0; i < vn.size(); i++) {
        if (pr > vr[1] || (pl <= vl[1] && v[pl] < v[pr])) {
            vn[i] = v[pl];
            pl++;
        } else {
            vn[i] = v[pr];
            pr++;
        }
    }

    for (int i = 0; i < vn.size(); i++) {
        v[vl[0] + i] = vn[i];
    }

    return {vl[0], vr[1]};
}

void MergeSort(std::vector<int>& v) {
    if (v.size() == 0) return;
    Merge(v, 0, v.size() - 1);
}

void PrintVector(std::vector<int> v) {
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main() {
    // auto v = std::vector<int>({1, 7, 4, 2, 4, 3, 5, 6});
    auto v = std::vector<int>({2, 1});
    MergeSort(v);
    PrintVector(v);
}
