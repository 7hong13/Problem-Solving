#include <iostream>
#define MAX 1000
using namespace std;
int arr[MAX];
int n;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void doInsertionSort() {
    for (int idx = 1; idx < n; idx++) {
        for (int subIdx = 0; subIdx < idx; subIdx++) {
            if (arr[idx] < arr[subIdx]) {
                swap(arr[idx], arr[subIdx]);
            }
        }
    }
}

int main() {
    init();
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> arr[idx];
    }
    doInsertionSort();
    for (int idx = 0; idx < n; idx++) {
        cout << arr[idx] << "\n";
    }
    return 0;
}