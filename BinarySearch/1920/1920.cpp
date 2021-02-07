#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;
ll arr[MAX];
int n, m;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void checkNumInArr() {
    sort(arr, arr + n);
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << binary_search(arr, arr + n, num) << "\n";
    }
}

int main() {
    init();
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> arr[idx];
    }
    checkNumInArr();
    return 0;
}