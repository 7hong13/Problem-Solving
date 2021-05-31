#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMinCnt(int n) {
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int cnt = 0;
    while (pq.size() != 1) {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        cnt += x + y;
        pq.push(x + y);
    }
    return cnt;
}

int main() {
    init();
    int n;
    cin >> n;
    int ans = findMinCnt(n);
    cout << ans;
    return 0;
}