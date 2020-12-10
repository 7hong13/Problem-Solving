#include <iostream>
#include <queue>
using namespace std;
bool visited[100001];
int N, K, sec = 0, popCnt = 0;
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int size = q.size();
    while (!q.empty()) {
        if (size == popCnt) {
            popCnt = 0;
            sec++;
            size = q.size();
        }
        int u = q.front();
        q.pop();
        popCnt++;
        if (u == K) {
            cout << sec << "\n";
            return;
        }
        int case1 = u - 1;
        int case2 = u + 1;
        int case3 = 2 * u;
        if (0 <= case1 && !visited[case1]) {
            q.push(case1);
            visited[case1] = true;
        }
        if (case2 <= 100000 && !visited[case2]) {
            q.push(case2);
            visited[case2] = true;
        }
        if (case3 <= 100000 && !visited[case3]) {
            q.push(case3);
            visited[case3] = true;
        }
    }
}

int main() {
    init(); 
    cin >> N >> K;
    bfs(N);
    return 0;
}
