#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100000 + 1
#define INF 99999999
using namespace std;
typedef pair<int, int> pii; //index, sec
int n, k, minSec = INF, cnt = 1;
bool visited[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    memset(visited, 0, sizeof(visited));
}

void bfs() {
    queue<pii> q;
    q.push(pii(n, 0));
    while (!q.empty()) {
        int x = q.front().first;
        int sec = q.front().second;
        q.pop();
        visited[x] = true;
        if (x == k) {
            if (minSec == INF) minSec = sec;
            else if (minSec == sec) cnt++;
            else if (minSec < sec) break;
        }
        int cases[3] = {x + 1, x - 1, x * 2};
        for (int idx = 0; idx < 3; idx++) {
            int nx = cases[idx];
            if (nx < 0 || nx > MAX) continue;
            if (!visited[nx]) {
                q.push(pii(nx, sec + 1));
            }
        }
    }
}

int main() {
    init();
    cin >> n >> k;
    bfs();
    cout << minSec << "\n" << cnt;
    return 0;
}