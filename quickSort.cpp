#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void qs(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int p = partition(arr, l, r);
    qs(arr, l, p - 1);
    qs(arr, p + 1, r);
}

vector<int> quicksort(vector<int>& arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    vector<int> test = {9, 2, 6, 8, 5, 4, 7, 3, 9, 2, 1};
    
    for (auto i : quicksort(test)) {
        cout << i << " ";
    }
}