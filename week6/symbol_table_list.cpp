#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Symbol {
    string key;
    int value;
};

list<Symbol> symbols;

// Khởi tạo bảng rỗng
void ST() {
    symbols.clear();
}

// Thêm khóa mới hoặc cập nhật giá trị nếu khóa đã tồn tại
void put(string key, int value) {
    for (Symbol &s : symbols) {
        if (s.key == key) {
            s.value = value;
            return;
        }
    }

    symbols.push_back({key, value});
}

// Lấy giá trị theo khóa
int get(string key) {
    for (const Symbol &s : symbols) {
        if (s.key == key) {
            return s.value;
        }
    }

    return -1;
}

// Kiểm tra khóa có tồn tại không
bool contains(string key) {
    for (const Symbol &s : symbols) {
        if (s.key == key) {
            return true;
        }
    }

    return false;
}

// Xóa phần tử có khóa tương ứng
void deleteKey(string key) {
    for (auto it = symbols.begin(); it != symbols.end(); ++it) {
        if (it->key == key) {
            symbols.erase(it);
            return;
        }
    }
}

// Kiểm tra bảng rỗng
bool isEmpty() {
    return symbols.empty();
}

// Trả về số cặp key-value
int size() {
    return static_cast<int>(symbols.size());
}

// In tất cả khóa
void keys() {
    for (const Symbol &s : symbols) {
        cout << s.key << '\n';
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

    return 0;
}