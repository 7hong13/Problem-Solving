#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int N;
int ropes[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxWeight() {
    sort(ropes, ropes + N);
    int maxWeight = -1;
    for (int idx = 0; idx < N; idx++) {
        maxWeight = max(maxWeight, ropes[idx] * (N - idx));
    }
    return maxWeight;
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> ropes[idx];
    }
    int ans = findMaxWeight();
    cout << ans;
    return 0;
}