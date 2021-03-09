#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000
using namespace std;
typedef pair<int, int> pii;
int T, N, M;
bool isUsed[MAX + 1];
pii nums[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countMaxStudents() {
    int cnt = 0;
    sort(nums, nums + M);
    for (int idx = 0; idx < M; idx++) {
        int start = nums[idx].second;
        int end = nums[idx].first;
        for (int num = start; num <= end; num++) {
            if (!isUsed[num]) {
                isUsed[num] = true;
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main() {
    init();
    cin >> T;
    while (T--) {
        memset(isUsed, 0, sizeof(isUsed));
        cin >> N >> M;
        for (int idx = 0; idx < M; idx++) {
            int start, end;
            cin >> start >> end;
            nums[idx] = pii(end, start);
        }
        int ans = countMaxStudents();
        cout << ans << "\n";
    }
    return 0;
}