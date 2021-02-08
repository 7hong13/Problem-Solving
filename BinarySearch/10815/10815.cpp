#include <iostream>
#include <algorithm>
#define MAX 500000
using namespace std;
int N, M;
int nums[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void checkWhetherNumExists() {
    sort(nums, nums + N);
    while (M--) {
        int num;
        cin >> num;
        cout << binary_search(nums, nums + N, num) << ' ';
    }
    cout << "\n";
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> nums[idx];
    }
    cin >> M;
    checkWhetherNumExists();
    return 0;
}