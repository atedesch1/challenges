struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
   public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
