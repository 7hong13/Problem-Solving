#include <iostream>
#include <cstring>
using namespace std;
int N;
int adjList[101][101];
bool visited[101];
void dfs(int row) {
    for (int col = 0; col < N; col++) {
        if (adjList[row][col] && !visited[col]) {
            visited[col] = true;
            dfs(col);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> adjList[row][col];
        }
    }
    for (int row = 0; row < N; row++) {
        memset(visited, 0, sizeof(visited));
        dfs(row);
        for (int col = 0; col < N; col++) {
            if (visited[col]) {
                adjList[row][col] = 1;
            }
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << adjList[row][col] << " ";
        }
        cout << "\n";
    }
    return 0;
}