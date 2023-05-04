#include <algorithm>
class MinStack {
   private:
    struct Node {
        int val;
        int min;
        Node* next;
        Node(int val, int min) : val(val), min(min), next(nullptr) {}
    };
    Node* head;

   public:
    MinStack() : head(nullptr) {}

    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val);
            return;
        }

        auto node = new Node(val, std::min(val, head->min));
        node->next = head;
        head = node;
    }

    void pop() {
        auto temp = head;
        head = head->next;
        delete temp;
    }

    int top() { return head->val; }

    int getMin() { return head->min; }
};
