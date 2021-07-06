#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> nums;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findMedian() {
    sort(nums.begin(), nums.end());
    return n % 2 == 0 ? nums[n / 2 - 1] : nums[n / 2];
}

int main() {
    init();
    cin >> n;
    for (int iter = 0; iter < n; iter++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int ans = findMedian();
    cout << ans;
    return 0;
}