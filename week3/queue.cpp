#include <iostream>
#include <stdexcept>
#include "List.cpp"
#include "Linked_List.cpp"

//su dung cac ham trong List.cpp.
class QueueUsingList {
    List list;
public:
    bool isEmpty() const { return list.isEmpty(); }

    // Them vao cuoi hang doi.
    void enqueue(int value) { list.insertAtTail(value); }

    // Xem phan tu dau, khong xoa.
    int front() const {
        if (isEmpty()) throw std::underflow_error("Queue rong");
        return list.at(0);
    }

    // Lay va xoa phan tu dau hang doi.
    int dequeue() {
        int value = front();
        list.deleteFirst();
        return value;
    }

    void display() const { list.display(); }
};

// su dung cac ham trong Linked_List.cpp.
class QueueUsingLinkedList {
    LinkedList list;
public:
    bool isEmpty() const { return list.head == nullptr; }

    void enqueue(int value) { list.insertAtTail(value); }

    int front() const {
        if (isEmpty()) throw std::underflow_error("Queue rong");
        return list.head->data;
    }

    int dequeue() {
        int value = front();
        list.deleteAtHead();
        return value;
    }

    void display() { list.display(); }
};

// FIFO: phan tu vao truoc se duoc lay ra truoc.
// List mang: enqueue O(1), dequeue O(n), front O(1).
// LinkedList: enqueue O(n), dequeue O(1), front O(1).
template <typename Queue>
void demoQueue(const char* name) {
    Queue queue;
    std::cout << name << '\n';
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    std::cout << "Queue (dau -> cuoi): ";
    queue.display();
    std::cout << "Front: " << queue.front() << '\n';
    while (!queue.isEmpty())
        std::cout << "Dequeue: " << queue.dequeue() << '\n';

    try {
        queue.dequeue();
    } catch (const std::underflow_error& error) {
        std::cout << error.what() << '\n';
    }

    // Hang doi van su dung duoc sau khi lay het phan tu.
    queue.enqueue(40);
    std::cout << "Them lai, dequeue: " << queue.dequeue() << "\n\n";
}

int main() {
    demoQueue<QueueUsingList>("Queue dung List.cpp");
    demoQueue<QueueUsingLinkedList>("Queue dung Linked_List.cpp");
    return 0;
}

