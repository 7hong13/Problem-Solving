#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 10
#define INF 10000001
using namespace std;
int N;
int idx = 0;
int start;
bool visited[MAX_SIZE];
int w[MAX_SIZE][MAX_SIZE];
int minCost = INF;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void dfs(int curr, int cnt, int cost) {
    if (cnt == N - 1) {
        if (w[curr][start]) {
            minCost = min(minCost, cost + w[curr][start]);
        }
        return;
    }
    for (int idx = 0; idx < N; idx++) {
        if (idx == curr) continue;
        if (!visited[idx] && w[curr][idx]) {
            visited[idx] = true;
            dfs(idx, cnt + 1, cost + w[curr][idx]);
            visited[idx] = false;
        }
    }  
}

int main() {
    init();
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> w[row][col];
        }
    }
    for (int idx = 0; idx < N; idx++) {
        start = idx;
        visited[idx] = true;
        dfs(idx, 0, 0);
        visited[idx] = false;
    }
    cout << minCost;
    return 0;
}