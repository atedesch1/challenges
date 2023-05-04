#include <iostream>
#include <memory>

template <typename T>
class ArrayQueue {
   private:
    std::unique_ptr<T[]> queue;
    int size;
    int capacity;
    int start, end;

   public:
    ArrayQueue() : queue(nullptr), size(0), capacity(0), start(-1), end(-1) {}

    int Size() { return size; }

    int Capacity() { return capacity; }

    void Enqueue(T value) {
        if (queue == nullptr) {
            capacity = 1;
            queue = std::make_unique<T[]>(capacity);
            start = 0;
        }

        if (size + 1 > capacity) {
            int new_capacity = capacity * 2;
            auto new_queue = std::make_unique<T[]>(new_capacity);
            for (int i = 0; i < size; i++) {
                new_queue[(start + i) % new_capacity] =
                    queue[(start + i) % capacity];
            }
            capacity = new_capacity;
            queue = std::move(new_queue);
        }

        end = (end + 1) % capacity;
        queue[end] = value;
        size++;
    }

    T Dequeue() {
        if (size == 0) {
            throw "No items in queue";
        }

        auto value = queue[start];
        start = (start + 1) % capacity;
        size--;
        return value;
    }

    T Peek() { return queue[start]; }

    void Print() {
        for (int i = 0; i < size; i++) {
            std::cout << queue[(start + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    auto q = ArrayQueue<int>();
    std::cout << "size is " << q.Size() << std::endl;
    q.Enqueue(1);
    std::cout << "size is " << q.Size() << std::endl;
    q.Enqueue(2);
    std::cout << "size is " << q.Size() << std::endl;
    q.Enqueue(3);
    std::cout << "size is " << q.Size() << std::endl;
    q.Enqueue(4);
    q.Enqueue(5);
    q.Print();
    auto val = q.Dequeue();
    std::cout << "value is " << val << std::endl;
    q.Print();
}
