#include <iostream>
#include <queue>
using namespace std;
int N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int cards() {
    queue<int> q;
    for (int num = 1; num <= N; num++) {
        q.push(num);
    }
    while (q.size() > 1) {
        q.pop();
        int n = q.front();
        q.pop();
        q.push(n);
    }
    return q.front();
}

int main() {
    init();
    cin >> N;
    int res = cards();
    cout << res;
    return 0;
}