#include <iostream>
#define MAX 1000
using namespace std;
int N;
bool checked[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isPrimeNum(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    for (int idx = 2; idx <= n; idx++) {
        if (!checked[idx]) {
            for (int subIdx = idx * idx; subIdx <= n; subIdx += idx) {
                if (!checked[subIdx]) checked[subIdx] = true;
            }
        }
    }
    return !checked[n];
}

int main() {
    init();
    cin >> N;
    int cnt = 0;
    while (N--) {
        int num;
        cin >> num;
        if (isPrimeNum(num)) cnt++;
    }
    cout << cnt;
    return 0;
}