#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
int dp[MAX + 1]; //idx starts from 1
int N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxPrice() {
    for (int num = 2; num <= N; num++) {
        for (int idx = 1; idx < num; idx++) {
            dp[num] = max(dp[num], dp[num - idx] + dp[idx]);
        }
    }
    return dp[N];
}

int main() {
    init();
    cin >> N;
    for (int idx = 1; idx <= N; idx++) {
        cin >> dp[idx];
    }
    int ans = findMaxPrice();
    cout << ans;
    return 0;   
}