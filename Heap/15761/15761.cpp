#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>, less<int> > pq;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countMinCows() {
    int curr_cnt = 0;
    while (N--) {
        if (pq.top() >= curr_cnt) curr_cnt++;
        pq.pop();
    }
    return curr_cnt;
}

int main() {
    init();
    cin >> N;
    for (int iter = 0; iter < N; iter++) {
        int num;
        cin >> num;
        pq.push(num);
    }
    int ans = countMinCows();
    cout << ans;
    return 0;
}