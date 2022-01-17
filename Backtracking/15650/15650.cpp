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
    for (int num = start; num <= N; num++) {
        visited[num] = true;
        dfs(num + 1, remaining - 1);
        visited[num] = false;
    }
}

int main() {
    init();
    cin >> N >> M;    
    
    dfs(1, M);
    return 0;
}
