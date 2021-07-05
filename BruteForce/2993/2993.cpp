#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string s;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void print1stWordInLex() {
    vector<string> list;
    string res, tmp;
    for (int first = 1; first < s.length() - 1; first++) {
        for (int mid = 1; first + mid < s.length(); mid++) {
            tmp = s.substr(0, first);
            reverse(tmp.begin(), tmp.end());
            res = tmp;

            tmp = s.substr(first, mid);
            reverse(tmp.begin(), tmp.end());
            res += tmp;

            tmp = s.substr(first + mid, s.length() - first - mid);
            reverse(tmp.begin(), tmp.end());
            res += tmp;

            list.push_back(res);
        }
    }

    sort(list.begin(), list.end());
    cout << list[0];
}

int main() {
    init();
    cin >> s;
    print1stWordInLex();
    return 0;
}