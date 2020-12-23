#include <iostream>
#include <cmath>
using namespace std;
int N, ans = 0;
int row[16];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool promising(int col) {
    int prevCol = 1;
    while (prevCol < col) {
        if (row[prevCol] == row[col] || abs(row[col] - row[prevCol]) == col - prevCol) {
            return false;
        }
        prevCol++;
    }
    return true;
}

void dfs(int col) {
    if (promising(col)) {
        if (col == N) {
            ans++;
            return;
        }
        else {
            for (int idx = 1; idx <= N; idx++) {
                row[col + 1] = idx;
                dfs(col + 1);
            }
        }
    }
}

int main() {
    init();
    cin >> N;
    dfs(0);
    cout << ans;
    return 0;
}