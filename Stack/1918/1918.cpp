#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<char> st;
string s;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findPostfixNotation() {
    for (int idx = 0; idx < s.length(); idx++) {
        if (65 <= s[idx] && s[idx] <= 90) {
            cout << s[idx];
        }
        else if (s[idx] == '*' || s[idx] == '/') {
            while (!st.empty()) {
                if (st.top() == '+' || st.top() == '-' || st.top() == '(') 
                    break;
                cout << st.top();
                st.pop();
            }
            st.push(s[idx]);
        }
        else if (s[idx] == '+' || s[idx] == '-') {
            while (!st.empty()) {
                if (st.top() == '(') break;
                cout << st.top();
                st.pop();
            }
            st.push(s[idx]);
        }
        else if (s[idx] == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop(); //= '('
        }
        else {
            st.push(s[idx]);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    init();
    cin >> s;
    findPostfixNotation();
    return 0;
}