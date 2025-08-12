#include <iostream>
using namespace std;

void merge_array(int a[], int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];  // Temporary array

    while (i <= mid && j <= e) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++]; 
    }

    while (j <= e) {
        temp[k++] = a[j++];
    }

    // Copy back to original array
    for (int l = s; l <= e; l++) {
        a[l] = temp[l];
    }
}

void merge_sort(int a[], int s, int e) {
    if (s >= e) return;

    int mid = (s + e) / 2;

    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);
    merge_array(a, s, e);
}

int main() {
    int a[] = {4, 2, 5, 7, 1};
    int n = sizeof(a) / sizeof(a[0]);

    merge_sort(a, 0, n - 1);

    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}