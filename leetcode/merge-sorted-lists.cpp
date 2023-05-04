struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedLists = nullptr;
        ListNode* ptr;

        while (list1 != nullptr || list2 != nullptr) {
            auto node = new ListNode();
            if (list2 == nullptr ||
                (list1 != nullptr && list1->val < list2->val)) {
                node->val = list1->val;
                list1 = list1->next;
            } else {
                node->val = list2->val;
                list2 = list2->next;
            }

            if (mergedLists == nullptr) {
                mergedLists = node;
                ptr = mergedLists;
            } else {
                ptr->next = node;
                ptr = ptr->next;
            }
        }

        return mergedLists;
    }
};
