
#include <iostream>
#include <stdexcept>

// Danh sach tuan tu: luu cac phan tu lien tiep trong mang.
// Vi tri duoc danh so tu 0 den size() - 1.
class List {
    static const int CAPACITY = 100;
    int data[CAPACITY];
    int length;
public:
    List() : length(0) {}
    bool isEmpty() const { return length == 0; }
    bool isFull() const { return length == CAPACITY; }
    int size() const { return length; }

    int at(int position) const {
        if (position < 0 || position >= length)
            throw std::out_of_range("Vi tri khong hop le");
        return data[position];
    }

    void insert(int value) { insert(value, 0); }
    void insert(int value, int position) {
        if (position < 0 || position > length)
            throw std::out_of_range("Vi tri khong hop le");
        if (isFull()) throw std::overflow_error("List day");
        // Dich sang phai de tao cho trong tai position.
        for (int i = length; i > position; --i)
            data[i] = data[i - 1];
        data[position] = value;
        ++length;
    }
    void insertAtTail(int value) { insert(value, length); }

    void deleteAt(int position) {
        if (position < 0 || position >= length)
            throw std::out_of_range("Vi tri khong hop le");
        // Dich sang trai de lap cho trong sau khi xoa.
        for (int i = position; i < length - 1; ++i)
            data[i] = data[i + 1];
        --length;
    }
    void deleteFirst() {
        if (!isEmpty()) deleteAt(0);
    }
    void deleteLast() {
        if (!isEmpty()) --length;
    }
    void display() const {
        for (int i = 0; i < length; ++i)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }
    void traverseForward() const { display(); }
    void traverseBackward() const {
        for (int i = length - 1; i >= 0; --i)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }
};

