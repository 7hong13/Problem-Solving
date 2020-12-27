#include <iostream>
#include <cstring>
using namespace std;
int N;
string ans = "";
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isBadSeq(int cnt) {
    for (int idx = 1; idx <= cnt / 2; idx++) {
        if (ans.substr(cnt - idx, idx) == ans.substr(cnt - idx * 2, idx)) 
            return true;
    }
    return false;
}

void dfs(int start, int cnt) {
    if (isBadSeq(cnt)) return;
    if (cnt == N) {
        cout << ans << "\n";
        exit(0);
    }
    for (int idx = start + 1; idx <= N; idx++) {
        for (int num = 1; num <= 3; num++) {
            char c = num + 48;
            ans += c;
            dfs(start + 1, cnt + 1);
            ans.erase(cnt);
        }
    }
}

int main() {
    init();
    cin >> N;
    dfs(0, 0);
    return 0;
}