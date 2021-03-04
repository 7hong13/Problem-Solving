#include <iostream>
#include <algorithm>
#define MAX 100000
#define INF 9999999999
using namespace std;
typedef long long ll;
int dist[MAX];
int prices[MAX];
int N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

ll findMinCost(ll distSum) {
    ll mn = INF;
    ll sum = 0;
    for (int idx = 0; idx < N - 1; idx++) {
        if (prices[idx] < mn) {
            mn = prices[idx];
        }
        sum += dist[idx + 1] * mn;
    }
    return sum;
}

int main() {
    init();
    cin >> N;
    ll distSum = 0;
    for (int idx = 1; idx < N; idx++) {
        cin >> dist[idx];
        distSum += dist[idx];
    }
    for (int idx = 0; idx < N; idx++) {
        cin >> prices[idx];
    }
    ll ans = findMinCost(distSum);
    cout << ans;
    return 0;
}