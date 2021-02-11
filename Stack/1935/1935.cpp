#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<double> st;
int N, nums[26];
string s;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

double calPostfix() {
    for (int idx = 0; idx < s.size(); idx++) {
        if (s[idx] == '+') {
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num1 + num2);
        }
        else if (s[idx] == '-') {
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num2 - num1);
        }
        else if (s[idx] == '*') {
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num1 * num2);
        }
        else if (s[idx] == '/') {
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num2 / num1);
        }
        else st.push(nums[s[idx] - 65]);
    }
    return st.top();
}

int main() {
    init();
    cin >> N;
    cin >> s;
    for (int idx = 0; idx < N; idx++) {
        cin >> nums[idx];
    }
    double ans = calPostfix();
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}