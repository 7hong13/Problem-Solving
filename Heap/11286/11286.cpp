#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (!x) {
            if (pq.empty()){
                cout << "0\n";
            }
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(pii(abs(x), x));
        }
    }
    return 0;
}