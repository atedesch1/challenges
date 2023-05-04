#include <forward_list>
#include <iostream>

template <typename T>
using LinkedList = std::forward_list<T>;

class Solution {
   public:
    LinkedList<int> ReverseLL(LinkedList<int>& ll) {
        if (ll.begin() == ll.end()) return ll;

        auto back = ll.begin();
        auto p = ++ll.begin();
        while (p != ll.end()) {
            ll.push_front(*p);
            p++;
            ll.erase_after(back);
        }
        return ll;
    }
};

int main() {
    auto ll = LinkedList<int>({1, 2, 3});
    ll = Solution().ReverseLL(ll);
    for (auto p = ll.begin(); p != ll.end(); p++) {
        std::cout << *p << " ";
    }
}
