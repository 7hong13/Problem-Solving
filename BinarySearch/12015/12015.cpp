#include <iostream>
#include <vector>
using namespace std;
int N, ans = 0;
vector<int> lis;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findLis() {
    lis.push_back(-1);
    while (N--) {
        int num;
        cin >> num;
        if (lis.back() < num) {
            lis.push_back(num);
            ans++;
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), num);
            *iter = num;
        }
    }
}

int main() {
    init();
    cin >> N;
    findLis();
    cout << ans;
    return 0;
}