#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#define MAX 100
using namespace std;
typedef long long ll;
int k, n, nums[MAX];
map<ll, bool> visited;
priority_queue<ll, vector<ll>, greater<ll> > pq;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findNthNumber() {
    pq.push(1);
    ll maxValue = 0;
    while (n--) {
        ll curr = pq.top();
        pq.pop();
        for (int idx = 0; idx < k; idx++) {
            ll next = curr * nums[idx];
            if (pq.size() > n && maxValue <= next) continue;
            if (!visited.count(next)) {
                pq.push(next);
                visited[next] = true;
                maxValue = max(maxValue, next);
            }
        }
    }
    return pq.top();
}

int main() {
    init();
    cin >> k >> n;
    for (int idx = 0; idx < k; idx++) {
        cin >> nums[idx];
    }
    int ans = findNthNumber();
    cout << ans;
    return 0;
}