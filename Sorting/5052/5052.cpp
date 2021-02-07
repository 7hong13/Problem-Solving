#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 10000
int t, n;
string nums[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

bool isConsistent() {
    for (int idx = 0; idx < n - 1; idx++) {
        string currStr = nums[idx];
        string nextStr = nums[idx + 1];
        bool isPrefix = true;
        for (int subIdx = 0; subIdx < nums[idx].size(); subIdx++) {
            if (currStr[subIdx] != nextStr[subIdx]) {
                isPrefix = false;
                break;
            }
        }
        if (isPrefix) return false;
    }
    return true;
}

int main() {
    init();
    cin >> t;
    while (t--) {
        cin >> n;
        for (int idx = 0; idx < n; idx++) {
            cin >> nums[idx];
        }
        sort(nums, nums + n);
        string ans = isConsistent() == true ? "YES\n" : "NO\n";
        cout << ans;
    }
    return 0;   
}