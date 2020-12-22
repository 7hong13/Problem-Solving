#include <iostream>
using namespace std;
int N, M;
bool visited[9];
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int start, int remaining) {
    if (!remaining) {
        for (int num = 1; num <= N; num++) {
            if (visited[num]) {
                cout << num << ' ';
            }
        }
        cout << "\n";
        return;
    }
    for (int num = start + 1; num <= N; num++) {
        visited[num] = true;
        dfs(num, remaining - 1);
        visited[num] = false;
    }
}

int main() {
    init();
    cin >> N >> M;
    for (int start = 1; start <= N; start++) {
        visited[start] = true;
        dfs(start, M - 1);
        visited[start] = false;
    }
    return 0;
}