 //Linked list chen phần tử vào đầu danh sách liên kết, vào vị trí bất kì, vào cuối danh sách liên kết và xóa phần tử đầu, phần tử cuối, phần tử bất kì trong danh sách liên kết. Cũng như duyệt xuôi và duyệt ngược danh sách liên kết.
    #include <iostream>
    using namespace std;
    struct Node {
        int data;
        Node* next;
    };
    //chen phan tu vao dau danh sach lien ket
    struct Linked List {
        Node* head;
        List() : head(nullptr) {}
        void insertAtHead(int value) {
            Node* newNode = new Node{value, head};
            head = newNode;
        }
        //chen phan tu vao cuoi danh sach lien ket
        void insertAtTail(int value) {
            Node* newNode = new Node{value, nullptr};
            if (!head) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        //chen phan tu vao vi tri bat ki trong danh sach lien ket
        void insertAtPosition(int value, int position) {
            if (position == 0) {
                insertAtHead(value);
                return;
            }
            Node* newNode = new Node{value, nullptr};
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp; ++i) {
                temp = temp->next;
            }
            if (temp) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                cout << "vị trí không hợp lệ" << endl;
                delete newNode;
            }
        }
        //xoa phan tu dau danh sach lien ket
        void deleteAtHead() {
            if (!head) return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        //xoa phan tu cuoi danh sach lien ket
        void deleteAtTail() {
            if (!head) return;
            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }
            Node* temp = head;
            while (temp->next && temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        //xoa phan tu bat ki trong danh sach lien ket
        void deleteAtPosition(int position) {
            if (position == 0) {
                deleteAtHead();
                return;
            }
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp; ++i) {
                temp = temp->next;
            }
            if (temp && temp->next) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
            } else {
                cout << "vị trí không hợp lệ" << endl;
            }
        }
        //duyet xuoi danh sach lien ket
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        //duyet nguoc danh sach lien ket
        void displayReverse(Node* node) {
            if (!node) return;
            displayReverse(node->next);
            cout << node->data << " ";
        }