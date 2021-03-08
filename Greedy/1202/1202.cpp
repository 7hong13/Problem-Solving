#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 300000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
pii jewels[MAX];
int knapsacks[MAX];
int N, K;
priority_queue<int, vector<int>, less<int>> pq;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool compareJewels(pii item1, pii item2) {
    if (item1.first == item2.first) return item1.second > item2.second;
    return item1.first < item2.first;
}

ll findMaxSum() {
    sort(jewels, jewels + N, compareJewels);
    sort(knapsacks, knapsacks + K);
    int jewelIdx = 0;
    ll sum = 0;
    for (int idx = 0; idx < K; idx++) {
        while (jewelIdx < N && jewels[jewelIdx].first <= knapsacks[idx]) {
            pq.push(jewels[jewelIdx++].second);
        }
        if (pq.empty()) continue;
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int main() {
    init();
    cin >> N >> K;
    for (int idx = 0; idx < N; idx++) {
        int weight, value;
        cin >> weight;
        cin >> value;
        jewels[idx] = pii(weight, value);
    }
    for (int idx = 0; idx < K; idx++) {
        cin >> knapsacks[idx];
    }
    ll ans = findMaxSum();
    cout << ans;
    return 0;
}