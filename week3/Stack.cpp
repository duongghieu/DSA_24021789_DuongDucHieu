#include <iostream>
#include <stdexcept>
#include "List.cpp"
#include "Linked_List.cpp"

// goi cac ham cua List.cpp.
class StackUsingList {
    List list;
public:
    bool isEmpty() const { return list.isEmpty(); }
    void push(int value) { list.insertAtTail(value); }
    int top() const {
        if (isEmpty()) throw std::underflow_error("Stack rong");
        return list.at(list.size() - 1);
    }
    int pop() {
        int value = top();
        list.deleteLast();
        return value;
    }
    void display() const { list.traverseBackward(); }
};

// goi cac ham cua Linked_List.cpp.
class StackUsingLinkedList {
    LinkedList list;
public:
    bool isEmpty() const { return list.head == nullptr; }
    void push(int value) { list.insertAtHead(value); }
    int top() const {
        if (isEmpty()) throw std::underflow_error("Stack rong");
        return list.head->data;
    }
    int pop() {
        int value = top();
        list.deleteAtHead();
        return value;
    }
    void display() { list.display(); }
};

// Ca hai stack deu theo LIFO: vao sau, ra truoc.
template <typename Stack>
void demo(const char* name) {
    Stack stack;
    std::cout << name << '\n';
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Stack (dinh -> day): ";
    stack.display();
    std::cout << "Top: " << stack.top() << '\n';
    while (!stack.isEmpty()) std::cout << "Pop: " << stack.pop() << '\n';
    try {
        stack.pop();
    } catch (const std::underflow_error& error) {
        std::cout << error.what() << "\n\n";
    }
}

int main() {
    demo<StackUsingList>("Stack dung List.cpp");
    demo<StackUsingLinkedList>("Stack dung Linked_List.cpp");
    return 0;
}

