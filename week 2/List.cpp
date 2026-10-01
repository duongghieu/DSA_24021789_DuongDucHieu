    #include <iostream>
    using namespace std;
    struct Node {
        int data;
        Node* next;
    };
    //chen phan tu vao dau danh sach lien ket
    struct List{
        Node* head;
        List() : head(nullptr) {}
        void insert(int value) {
            Node* newNode = new Node{value, head};
            head = newNode;
        }
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    //chen phan tu vao vi tri bat ki trong danh sach lien ket
    struct List{
        Node* head;
        List() : head(nullptr) {}
        void insert(int value, int position) {
            Node* newNode = new Node{value, nullptr};
            if (position == 0) {
                newNode->next = head;
                head = newNode;
                return;
            }
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp; ++i) {
                temp = temp->next;
            }
            if (temp) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                cout << "Position out of bounds" << endl;
                delete newNode; // Free memory if position is invalid
            }
        }
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    //chen phan tu vao cuoi danh sach lien ket
    struct List{
        Node* head;
        List() : head(nullptr) {}
        void insert(int value) {
            Node* newNode = new Node{value, nullptr};
            if (!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    //xoa phan tu dau danh sach lien ket
    struct List{
        Node* head;
        List() : head(nullptr) {}
        void deleteFirst() {
            if (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            } else {
                cout << "List is empty" << endl;
            }
        }
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    //xoa phan tu cuoi danh sach lien ket
    struct List{
        Node* head;
        List() : head(nullptr) {}
        void deleteLast() {
            if (!head) {
                cout << "List is empty" << endl;
                return;
            }
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
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    //xoa phan tu bat ki trong danh sach lien ket
    struct List{
        Node* head;
        List() : head(nullptr) {}
        void deleteAt(int position) {
            if (!head) {
                cout << "List is empty" << endl;
                return;
            }
            if (position == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
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
                cout << "Position out of bounds" << endl;
            }
        }
        void display() {
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
    //duyet xuoi danh sach lien ket
    void traverseForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    //duyet nguoc danh sach lien ket
    void traverseBackward(Node* node) {
        if (!node) return;
        traverseBackward(node->next);
        cout << node->data << " ";
    }