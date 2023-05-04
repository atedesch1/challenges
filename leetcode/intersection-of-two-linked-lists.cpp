#include <algorithm>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto seen = std::unordered_set<ListNode *>();
        auto pA = headA;
        auto pB = headB;

        while (true) {
            if (pA == pB) return pA;
            if (seen.find(pA) != seen.end()) return pA;
            if (seen.find(pB) != seen.end()) return pB;
            if (pA != nullptr) {
                seen.insert(pA);
                pA = pA->next;
            }
            if (pB != nullptr) {
                seen.insert(pB);
                pB = pB->next;
            }
        }
    }

    ListNode *getIntersectionNodeImproved(ListNode *headA, ListNode *headB) {
        auto sizeA = sizeOfLinkedList(headA);
        auto sizeB = sizeOfLinkedList(headB);
        auto diff = std::abs(sizeA - sizeB);
        ListNode *pLong, *pShort;
        if (sizeA >= sizeB) {
            pLong = headA;
            pShort = headB;
        } else {
            pLong = headB;
            pShort = headA;
        }

        for (int i = 0; i < diff; i++) {
            pLong = pLong->next;
        }

        while (pLong != pShort) {
            pLong = pLong->next;
            pShort = pShort->next;
        }

        return pLong;
    }

    int sizeOfLinkedList(ListNode *p) {
        int size = 0;
        while (p != nullptr) {
            p = p->next;
            size++;
        }
        return size;
    }
};
