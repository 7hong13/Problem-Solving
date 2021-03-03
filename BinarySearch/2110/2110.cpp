#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;
int houses[MAX];
int N, C;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool canBeAnswer(int dist) {
    int prev = houses[0];
    int cnt = 1;
    for (int idx = 1; idx < N; idx++) {
        if (houses[idx] - prev >= dist) {
            cnt++;
            prev = houses[idx];
        }
    }
    if (C <= cnt) return true;
    return false;
}

int findMaxDist() {
    sort(houses, houses + N);
    int left = 1;
    int right = houses[N - 1] - houses[0];
    int mid;
    int maxDist = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (canBeAnswer(mid)) {
            maxDist = max(maxDist, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return maxDist;
}

int main() {
    init();
    cin >> N >> C;
    for (int idx = 0; idx < N; idx++) {
        cin >> houses[idx];
    }
    int ans = findMaxDist();
    cout << ans;
    return 0;
}