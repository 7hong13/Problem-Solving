#include <iostream>
#include <stack>
using namespace std;
int N, P;
stack<int> st[6];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int countMinFingering() {
    int cnt = 0;
    while (N--) {
        int line, fret;
        cin >> line >> fret;
        if (st[line - 1].empty()) {
            st[line - 1].push(fret);
            cnt++;
        }
        else if (st[line - 1].top() < fret) {
            st[line - 1].push(fret);
            cnt++;
        }
        else if (st[line - 1].top() > fret) {
            while (!st[line - 1].empty() && st[line - 1].top() > fret) {
                st[line - 1].pop();
                cnt++;
            }
            if (!st[line - 1].empty() && st[line - 1].top() == fret) continue;
            st[line - 1].push(fret);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    init();
    cin >> N >> P;
    int ans = countMinFingering();
    cout << ans;
    return 0;
}