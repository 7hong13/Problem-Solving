#include <iostream>
#define MAX 1000
using namespace std;
int N, K;
bool num[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findKthNum() {
    int cnt = 0;
    for (int idx = 2; idx <= N; idx++) {
        if (!num[idx]) {
            for (int subIdx = idx; subIdx <= N; subIdx += idx) {
                if (num[subIdx]) continue;
                num[subIdx] = true;
                cnt++;
                if (cnt == K) return subIdx;
            }
        }
    }
    return -1;
}

int main() {
    init();
    cin >> N >> K;
    int ans = findKthNum();
    cout << ans;
    return 0;
}