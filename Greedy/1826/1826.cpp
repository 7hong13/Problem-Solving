#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 10000
using namespace std;
typedef pair<int, int> pii;
pii stations[MAX]; //start, end
priority_queue<int, vector<int>, less<int>> pq; //P
int N, L, P;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countMinStopping() {
    if (L <= P) return 0;
    sort(stations, stations + N);
    int cnt = 0;
    int maxEnd = P;
    int idx = 0;
    while (maxEnd < L) {
        while (idx < N && stations[idx].first <= maxEnd) {
            pq.push(stations[idx].second);
            idx++;
        }
        if (pq.empty()) return -1;
        maxEnd += pq.top();
        pq.pop();
        cnt++;
    }
    return L <= maxEnd ? cnt : -1;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        int a, b;
        cin >> a >> b;
        stations[idx] = pii(a, b);
    }
    cin >> L >> P;
    int ans = countMinStopping();
    cout << ans;
    return 0;
}