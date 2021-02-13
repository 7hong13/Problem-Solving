#include <iostream>
#include <algorithm>
#define MAX 100000
#define INF 999999999
using namespace std;
int N, trees[MAX], interval[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMinNewTrees() {
    if (N == 1 || N == 2) return 0;
    sort(trees, trees + N);
    int minIntv = INF;
    for (int idx = 0; idx < N - 1; idx++) {
        interval[idx] = trees[idx + 1] - trees[idx];
        minIntv = min(minIntv, interval[idx]);
    }
    int intv = 1;
    int minTrees = INF;
    while (intv <= minIntv) {
        int sum = 0;
        bool isUsable = true;
        for (int idx = 0; idx < N - 1; idx++) {
            if (interval[idx] % intv != 0) {
                isUsable = false;
                break;
            }
            sum += interval[idx] / intv - 1;
        }
        if (isUsable) minTrees = min(minTrees, sum);
        intv++;
    }
    return minTrees;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> trees[idx];
    }
    int ans = findMinNewTrees();
    cout << ans;
    return 0;
}