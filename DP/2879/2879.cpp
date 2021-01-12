#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 1000
int currTab[MAX + 1], diff[MAX + 1], dp[MAX + 1], N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isPosNum(int n) {
    return n > 0;
}

int countMinEditing() {
    dp[0] = abs(diff[0]);
    for (int idx = 1; idx < N; idx++) {
        if (isPosNum(diff[idx]) == isPosNum(diff[idx - 1])) {
            int mn = min(abs(diff[idx]), abs(diff[idx - 1]));
            int value = mn + abs(diff[idx] - diff[idx - 1]) + dp[idx - 1] - abs(diff[idx - 1]);
            dp[idx] = min(dp[idx - 1] + abs(diff[idx]), value);
        }
        else {
            dp[idx] = abs(diff[idx]) + dp[idx - 1];
        }
    }
    return dp[N - 1];
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> currTab[idx];
    }
    for (int idx = 0; idx < N; idx++) {
        int tabNum;
        cin >> tabNum;
        diff[idx] = tabNum - currTab[idx];
    }
    int ans = countMinEditing();
    cout << ans;
    return 0;
}