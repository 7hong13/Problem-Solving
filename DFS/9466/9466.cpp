#include <iostream>
#include <cstring>
#define MAX 100000
using namespace std;
int T, n, selected[MAX + 1], teamStudentCnt = 1;
bool isDone[MAX + 1], visited[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int sx) {
    visited[sx] = true;
    int sy = selected[sx];
    if (!visited[sy]) {
        dfs(sy);
    }
    else if (!isDone[sy]) {
        for (int idx = sy; idx != sx; idx = selected[idx]) {
            teamStudentCnt++;
        }
        teamStudentCnt++;
    }
    isDone[sx] = true;
}

int main() {
    init();
    cin >> T;
    while (T--) {
        cin >> n;
        teamStudentCnt = 0;
        memset(isDone, 0, sizeof(isDone));
        memset(visited, 0, sizeof(visited));
        for (int idx = 1; idx <= n; idx++) {
            cin >> selected[idx];
        }
        for (int idx = 1; idx <= n; idx++) {
            if (!visited[idx]) dfs(idx);
        }
        cout << n - teamStudentCnt << "\n";
    }
    return 0;
}