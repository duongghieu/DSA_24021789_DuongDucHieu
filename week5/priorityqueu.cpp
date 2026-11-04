
#include <iostream>
#include <algorithm>
using namespace std;

void swim(int pq[], int k) {
    while (k > 1 && pq[k / 2] < pq[k]) {
        swap(pq[k], pq[k / 2]);
        k = k / 2;
    }
}

void sink(int pq[], int k, int N) {
    while (2 * k <= N) {
        int j = 2 * k;

        if (j < N && pq[j] < pq[j + 1])
            j++;

        if (pq[k] >= pq[j])
            break;

        swap(pq[k], pq[j]);
        k = j;
    }
}

// Them phan tu
void push(int pq[], int& n, int value) {
    n++;
    pq[n] = value;
    swim(pq, n);
}

// Xem phan tu uu tien cao nhat
int top(int pq[], int n) {
    if (n == 0) return -1;
    return pq[1];
}

// Lay va xoa phan tu lon nhat
int pop(int pq[], int& n) {
    if (n == 0) return -1;

    int result = pq[1];

    pq[1] = pq[n];
    n--;

    if (n > 0)
        sink(pq, 1, n);

    return result;
}

int main() {
    int capacity;
    cin >> capacity;

    if (capacity < 0) return 0;

    int* pq = new int[capacity + 1];
    int n = 0;

    for (int i = 0; i < capacity; i++) {
        int x;
        cin >> x;
        push(pq, n, x);
    }

    if (n > 0)
        cout << "Max: " << top(pq, n) << endl;

    cout << "Priority Queue: ";
    while (n > 0) {
        cout << pop(pq, n) << " ";
    }

    delete[] pq;
    return 0;
}
