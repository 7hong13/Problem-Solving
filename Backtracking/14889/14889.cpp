#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 20
#define INF 9999
using namespace std;
int N, minDiff = INF;
int value[MAX][MAX];
bool visited[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int calDiff(vector<int> start, vector<int> link) {
    int startSum = 0, linkSum = 0;
    for (int idx1 = 0; idx1 < N / 2; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < N / 2; idx2++) {
            int startRow = start[idx1], startCol = start[idx2];
            int linkRow = link[idx1], linkCol = link[idx2];
            startSum += value[startRow][startCol] + value[startCol][startRow];
            linkSum += value[linkRow][linkCol] + value[linkCol][linkRow];
        }
    }
    return abs(startSum - linkSum);
}

void dfs(int begin, int cnt) {
    if  (cnt == N / 2) {
        vector<int> start, link;
        for (int idx = 0; idx < N; idx++) {
            if (visited[idx]) start.push_back(idx);
            else link.push_back(idx);
        }
        int diff = calDiff(start, link);
        minDiff = min(minDiff, diff);
        return;
    }
    for (int idx = begin; idx < N; idx++) {
        visited[idx] = true;
        dfs(idx + 1, cnt + 1);
        visited[idx] = false;
    }
}

int main() {
    init();
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> value[row][col];
        }
    }
    dfs(0, 0);
    cout << minDiff;
    return 0;  
}