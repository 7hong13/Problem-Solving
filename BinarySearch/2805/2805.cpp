#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
typedef long long ll;
int N, M;
ll mx = -1;
ll trees[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

ll findMaxHgt() {
    ll left = 0, right = mx, mid;
    while (left + 1 < right) {
        mid = (left + right) / 2;
        ll sum = 0;
        for (int idx = 0; idx < N; idx++) {
            ll remain = trees[idx] - mid;
            if (remain > 0) sum += remain;
        }
        if (sum < M) {
            right = mid;
        }
        else if (sum > M) {
            left = mid;
        }
        else {
           return mid;
        }
    }
    return left;
}

int main() {
    init();
    cin >> N >> M;
    for (int idx = 0; idx < N; idx++) {
        cin >> trees[idx];
        mx = max(mx, trees[idx]);
    }
    ll h = findMaxHgt();
    cout << h;
    return 0;
}