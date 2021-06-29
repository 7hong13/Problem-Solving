#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N1, N2, T;
string s1, s2;
bool isN1[26];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

string findSeqAfterT() {
    for (int idx = 0; idx < N1; idx++) {
        isN1[s1[idx] - 65] = true;
    }
    reverse(s1.begin(), s1.end());
    string combined = s1 + s2;

    while (T--) {
        for (int idx = 0; idx < N1 + N2 - 1; idx++) {
            if (isN1[combined[idx] - 65] && 
                isN1[combined[idx] - 65] != isN1[combined[idx + 1] - 65]) {
                swap(combined[idx], combined[idx + 1]);
                idx++;
            }
        }
    }
    return combined;
}

int main() {
    init();
    cin >> N1 >> N2;
    cin >> s1 >> s2;
    cin >> T;
    string ans = findSeqAfterT();
    cout << ans;
    return 0;
}