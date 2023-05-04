#include <iostream>
#include <memory>

template <typename T>
class LinkedList {
   private:
    struct Node {
        T value;
        std::unique_ptr<Node> next;

        Node(T value) : value(value), next(nullptr) {}
    };
    std::unique_ptr<Node> head;
    int length;

   public:
    LinkedList() : head(nullptr), length(0) {}
    ~LinkedList() { clean(); }

    void clean() {
        while (this->head != nullptr) {
            this->head = std::move(this->head->next);
        }
    }

    int Size() { return this->length; }

    Node* Get(int index) {
        if (this->length <= index) {
            return nullptr;
        }

        auto p = this->head.get();
        for (int i = 0; i < index; i++) {
            p = p->next.get();
        }
        return p;
    }

    void Insert(T value, int index) {
        if (index == 0) return this->PushFront(value);

        auto p = this->Get(index - 1);
        if (p == nullptr) return;

        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(p->next);
        p->next = std::move(newNode);
        this->length++;
    }

    std::unique_ptr<Node> Remove(int index) {
        auto p = this->Get(index - 1);
        if (p == nullptr || p->next == nullptr) return nullptr;

        auto node = std::move(p->next);
        p->next = std::move(node->next);
        this->length--;
        return node;
    }

    void PushFront(T value) {
        auto newNode = std::make_unique<Node>(value);
        if (this->head == nullptr) {
            this->head = std::move(newNode);
        } else {
            newNode->next = std::move(this->head);
            this->head = std::move(newNode);
        }
        this->length++;
    }

    std::unique_ptr<Node> PopFront() {
        if (this->head == nullptr) {
            return nullptr;
        }
        auto node = std::move(this->head);
        this->head = std::move(node->next);
        this->length--;
        return node;
    }

    void PushBack(T value) {
        auto newNode = std::make_unique<Node>(value);
        if (this->head == nullptr) {
            this->head = std::move(newNode);
        } else {
            auto p = this->head.get();
            for (; p->next != nullptr; p = p->next.get())
                ;
            p->next = std::move(newNode);
        }
        this->length++;
    }

    std::unique_ptr<Node> PopBack() {
        if (this->head == nullptr) {
            return nullptr;
        } else if (this->length == 1) {
            this->length--;
            return std::move(this->head);
        }
        auto p = this->head.get();
        for (; p->next->next != nullptr; p = p->next.get())
            ;
        this->length--;
        return std::move(p->next);
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll);
};

std::ostream& operator<<(std::ostream& os, const LinkedList<int>& ll) {
    auto p = ll.head.get();
    while (p != nullptr) {
        os << p->value << ' ';
        p = p->next.get();
    }
    return os;
}

int main() {
    LinkedList<int> ll;
    ll.PopBack();
    ll.PopFront();

    ll.PushFront(1);
    std::cout << ll << std::endl;
    ll.PopBack();
    std::cout << ll << std::endl;
    ll.PushBack(1);
    std::cout << ll << std::endl;
    auto p = ll.PopFront();
    std::cout << ll << std::endl;
    std::cout << p->value << std::endl;
    ll.PushBack(1);
    ll.PushBack(2);
    ll.PushBack(3);
    ll.PushBack(4);
    ll.PushFront(0);
    ll.Insert(-1, 0);
    std::cout << ll << std::endl;
    auto p1 = ll.Get(2);
    std::cout << p1->value << std::endl;
    auto p2 = ll.Remove(2);
    std::cout << p2->value << std::endl;
    std::cout << ll << std::endl;
}
