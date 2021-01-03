#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int arrA[1001], N;
deque<int> dp[1001];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findLis() {
    for (int currIdx = 1; currIdx < N; currIdx++) {
        int mx = dp[currIdx].size();
        int mxIdx = currIdx;
        bool isChanged = false;
        for (int prevIdx = 0; prevIdx < currIdx; prevIdx++) {
            if (dp[currIdx].back() <= dp[prevIdx].back()) continue;
            int size = dp[prevIdx].size() + 1;
            if (mx < size) {
                mx = size;
                mxIdx = prevIdx;
            }
            isChanged = true;
        }
        if (isChanged) {
            int len = dp[mxIdx].size();
            for (int idx = len - 1; 0 <= idx; idx--) {
                dp[currIdx].push_front(dp[mxIdx][idx]);
            }
        }
    }
    int mx = -1, mxIdx = -1;
    for (int idx = 0; idx < N; idx++) {
        int size = int(dp[idx].size());
        if (mx < size) {
            mx = size;
            mxIdx = idx;
        }
    }
    cout << dp[mxIdx].size() << "\n";
    for (int idx = 0; idx < dp[mxIdx].size(); idx++) {
        cout << dp[mxIdx][idx] << ' ';
    }
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> arrA[idx];
        dp[idx].push_back(arrA[idx]);
    }
    findLis();
    return 0;
}