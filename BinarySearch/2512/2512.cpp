#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
int N, M;
int budgets[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMaxBudget(int sum) {
    sort(budgets, budgets + N);
    if (sum <= M) return budgets[N - 1];
    int left = 1;
    int right = budgets[N - 1];
    int mid = right;
    while (left + 1 < right) {
        int tmpSum = 0;
        for (int idx = 0; idx < N; idx++) {
            if (budgets[idx] <= mid) tmpSum += budgets[idx];
            else {
                tmpSum += mid;
            }
        }
        if (tmpSum > M) right = mid;
        else if (tmpSum <= M) left = mid;
        mid = (left + right) / 2;
    }
    return left;
}

int main() {
    init();
    cin >> N;
    int sum = 0;
    for (int idx = 0; idx < N; idx++) {
        cin >> budgets[idx];
        sum += budgets[idx];
    }
    cin >> M;
    int ans = findMaxBudget(sum);
    cout << ans;
    return 0;
}