
#include <iostream>
#include <algorithm>
using namespace std;

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

void heapSort(int a[], int n) {
    // Xay dung Max Heap
    int start = n / 2;
    while (start >= 1) {
        sink(a, start, n);
        start--;
    }

    // Sap xep mang tang dan
    for (int end = n; end > 1; end--) {
        swap(a[1], a[end]);
        sink(a, 1, end - 1);
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 0) return 0;

    int* a = new int[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    heapSort(a, n);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    delete[] a;
    return 0;
}
