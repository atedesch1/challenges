#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        auto curr = head;

        while (curr != nullptr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = prev;
        return h2;
    }
};

int main() {
    auto ll = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
    auto fll = Solution().reverseList(ll);

    for (auto ptr = fll; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->val << " ";
    }
}
