#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
bool isParenthesisString(string s) {
    if (s.size() % 2 != 0) {
        return false;
     }
    stack<char> st;
    for (int idx = 0; idx < s.size(); idx++) {
        if (s[idx] == '(') st.push('(');
        else if (st.empty() && s[idx] == ')') {
            return false;
        }
        else {
            st.pop();
        }
    }
    bool result = st.empty() ? true : false;  
    return result;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string result = isParenthesisString(s) ? "YES" : "NO";
        cout << result << "\n";
    }
    return 0;
}