#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000
using namespace std;
int K, N;
string nums[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool compareForExtra(string s1, string s2) {
    if (s1.length() == s2.length()) return s1 > s2;
    return s1.length() > s2.length();
}

bool compareCombined(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

string findMaxNum() {
    string mx = "";
    sort(nums, nums + K, compareForExtra);
    for (int idx = K; idx < N; idx++) {
        nums[idx] = nums[0];
    }
    sort(nums, nums + N, compareCombined);
    for (int idx = 0; idx < N; idx++) {
        mx += nums[idx];
    }
    return mx;
}

int main() {
    init();
    cin >> K >> N;
    for (int idx = 0; idx < K; idx++) {
        cin >> nums[idx];
    }
    string ans = findMaxNum();
    cout << ans;
    return 0;
}