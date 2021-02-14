#include <iostream>
#include <algorithm>
#define MAX 4000000
using namespace std;
int N;
bool isPrimeNum[MAX + 1]; //idx starts from 1
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(isPrimeNum, isPrimeNum + MAX, 1);
}

void checkPrimeNum() {
    isPrimeNum[1] = false;
    for (int num = 2; num * num <= N; num++) {
        if (isPrimeNum[num]) {
            for (int idx = num * num; idx <= N; idx += num) {
                if (isPrimeNum[idx]) isPrimeNum[idx] = false;
            }
        }
    }
}

int countNumOfCases() {
    checkPrimeNum();
    int cnt = 0;
    for (int start = 2; start <= N; start++) {
        if (!isPrimeNum[start]) continue;
        int sum = 0;
        for (int idx = start; idx <= N; idx++) {
            if (isPrimeNum[idx]) sum += idx;
            if (sum >= N) {
                break;
            }
        }
        if (sum == N) cnt++;
    }
    return cnt;
}

int main() {
    init();
    cin >> N;
    int ans = countNumOfCases();
    cout << ans;
    return 0;
}