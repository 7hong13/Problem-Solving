#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1000
using namespace std;
int N;
int parent[MAX + 1];
bool visited[MAX + 1];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countPermCycles() {
    int cnt = 0;
    for (int start = 1; start <= N; start++) {
        if (visited[start]) continue;
        int idx = start;
        visited[start] = true;
        while (parent[idx] != start) {
            idx = parent[idx];
            visited[idx] = true;
        }
        cnt++;
    }
    return cnt;
}


int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        memset(parent, -1, sizeof(parent));
        memset(visited, 0, sizeof(visited));
        for (int idx = 0; idx < N; idx++) {
            int n;
            cin >> n;
            parent[idx + 1] = n;
        }
        int cnt = countPermCycles();
        cout << cnt << "\n";
    }
    return 0;
}