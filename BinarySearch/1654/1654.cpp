#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
typedef long long ll;
int K, N;
int wires[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

ll findMaxLength() {
    sort(wires, wires + K);
    ll maxLen = wires[K - 1];
    ll left = 1;
    ll right = maxLen;
    ll mid = right;
    while (left + 1 < right) {
        ll sum = 0;
        for (int idx = 0; idx < K; idx++) {
            sum += wires[idx] / mid;
        }
        if (sum < N) right = mid;
        else if (sum >= N) left = mid;
        mid = (left + right) / 2;
    }
    return left;
}

int main() {
    init();
    cin >> K >> N;
    for (int idx = 0; idx < K; idx++) {
        cin >> wires[idx];
    }
    ll ans = findMaxLength();
    cout << ans;
    return 0;
}