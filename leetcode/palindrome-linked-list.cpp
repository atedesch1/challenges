#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        auto s = std::stack<int>();
        int size = 0;
        for (auto p = head; p != nullptr; p = p->next, size++)
            ;
        int i = 1;
        for (auto p = head; p != nullptr; p = p->next, i++) {
            if (size % 2 != 0 && i == size / 2 + 1) {
                continue;
            } else if (i <= size / 2) {
                s.push(p->val);
            } else if (s.top() != p->val) {
                return false;
            } else {
                s.pop();
            }
        }
        return true;
    }

    bool isPalindromeImproved(ListNode *head) {
        int size = 0;
        for (auto p = head; p != nullptr; p = p->next, size++)
            ;
        if (size < 2) {
            return true;
        } else if (size == 2) {
            return head->val == head->next->val;
        }

        auto p1 = head;
        for (int i = 1; i < (size + 1) / 2; i++, p1 = p1->next)
            ;

        auto p2 = p1->next;
        p1->next = nullptr;
        if (size % 2 == 0) {
            p1 = p2;
            p2 = p2->next;
            p1->next = nullptr;
        }

        while (p2 != nullptr) {
            auto temp = p2->next;
            p2->next = p1;
            p1 = p2;
            if (temp == nullptr) break;
            p2 = temp;
        }

        p1 = head;
        while (p1 != nullptr) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
