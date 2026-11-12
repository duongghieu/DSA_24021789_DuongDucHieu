#include <iostream>
#include <string>

using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
};

Node* head = nullptr;
int cnt = 0;

// Xóa toàn bộ bảng, đưa về trạng thái rỗng
void ST() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cnt = 0;
}

// Thêm khóa mới hoặc cập nhật khóa đã tồn tại
void put(string key, int value) {
    Node* current = head;
    Node* last = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }

        last = current;
        current = current->next;
    }

    Node* newNode = new Node{key, value, nullptr};

    if (last == nullptr) {
        head = newNode;
    } else {
        last->next = newNode;
    }

    cnt++;
}

// Lấy giá trị theo khóa
int get(string key) {
    Node* current = head;

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }

        current = current->next;
    }

    return -1;
}

// Kiểm tra khóa có tồn tại không
bool contains(string key) {
    Node* current = head;

    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }

        current = current->next;
    }

    return false;
}

// Xóa phần tử theo khóa
void deleteKey(string key) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (previous == nullptr) {
                // Xóa node đầu
                head = current->next;
            } else {
                // Nối node trước với node sau
                previous->next = current->next;
            }

            delete current;
            cnt--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

// Kiểm tra bảng rỗng
bool isEmpty() {
    return head == nullptr;
}

// Số cặp key-value
int size() {
    return cnt;
}

// In tất cả khóa
void keys() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->key << '\n';
        current = current->next;
    }
}

int main() {
    ST();

    put("apple", 10);
    put("banana", 20);
    put("orange", 30);

    if (contains("banana")) {
        cout << "Gia tri cua banana: " << get("banana") << '\n';
    }

    cout << "Co apple khong? "
         << (contains("apple") ? "Co" : "Khong") << '\n';

    deleteKey("apple");

    cout << "So cap key-value: " << size() << '\n';
    cout << "Bang rong? " << (isEmpty() ? "Co" : "Khong") << '\n';

    cout << "Cac key trong bang:\n";
    keys();

    ST();

    return 0;
}