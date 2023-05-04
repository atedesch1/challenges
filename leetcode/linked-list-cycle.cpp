#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        auto seen = std::unordered_set<ListNode *>();
        auto p = head;
        while (p != nullptr) {
            if (seen.find(p) != seen.end()) {
                return true;
            }
            seen.insert(p);
            p = p->next;
        }

        return false;
    }

    bool hasCycleFast(ListNode *head) {
        if (head == nullptr) return false;
        auto pSlow = head;
        auto pFast = head->next;
        while (pFast != nullptr && pSlow != nullptr) {
            if (pFast == pSlow) return true;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast != nullptr) {
                pFast = pFast->next;
            }
        }
        return false;
    }
};
