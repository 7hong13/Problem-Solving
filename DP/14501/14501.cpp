#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;
typedef pair<int, int> pii;
int N;
pii list[MAX]; //time, price
int dp[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxProfit() {
    for (int last = 0; last < N; last++) {
        if (last + list[last].first > N) {
            dp[last] = last == 0 ? 0 : dp[last - 1];
            continue;
        }
        for (int idx = 0; idx < last; idx++) {
            int prevRange = list[idx].first;
            if (idx + prevRange <= last) {
                dp[last] = max(dp[idx] + list[last].second, dp[last]);
            }
        }
    }
    int mx = -1;
    for (int idx = 0; idx < N; idx++) {
        mx = max(dp[idx], mx);
    }
    return mx;
}


int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> list[idx].first;
        cin >> list[idx].second;
        dp[idx] = list[idx].second;
    }
    int ans = findMaxProfit();
    cout << ans;
    return 0;
}