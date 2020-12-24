#include <iostream>
#include <cstring>
using namespace std;
int seq[14], k;
bool used[14];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int start, int remaining) {
    if (remaining == 0) {
        for (int idx = 0; idx < k; idx++) {
            if (used[idx]) {
                cout << seq[idx] << ' ';
            }
        }
        cout << "\n";
    }
    for (int num = start + 1; num < k; num++) {
        used[num] = true;
        dfs(num, remaining - 1);
        used[num] = false;
    }
}

int main() {
    init();
    cin >> k;
    while (k != 0) {
        memset(used, 0, sizeof(used));
        for (int idx = 0; idx < k; idx++) {
            cin >> seq[idx];
        }
        for (int start = 0; start < k; start++) {
            used[start] = true;
            dfs(start, 6 - 1);
            used[start] = false;
        }
        cout << "\n";
        cin >> k;
    }
    return 0;
}