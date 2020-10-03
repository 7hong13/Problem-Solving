#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        stack<char> st;
        if (s.size() % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        bool invalid = false;
        for (int idx = 0; idx < s.size(); idx++) {
            if (s[idx] == '(') st.push('(');
            else if (st.empty() && s[idx] == ')') {
                invalid = true;
                cout << "NO\n";
                break;
            }
            else {
                st.pop();
            }
        }
        if (invalid) continue;
        string result = st.empty() ? "YES" : "NO";
        cout << result << "\n";
    }
    return 0;
}