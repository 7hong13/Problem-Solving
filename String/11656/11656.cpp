#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string s;
vector<string> v;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printSuffixInLexOrder() {
    int len = s.length();
    for (int idx = 0; idx < s.length(); idx++) {
        v.push_back(s.substr(idx, s.length() - idx));
    }

    sort(v.begin(), v.end());
    for (int idx = 0; idx < s.length(); idx++) {
        cout << v[idx] << "\n";
    }
}

int main() {
    init();
    cin >> s;
    printSuffixInLexOrder();
    return 0;
}