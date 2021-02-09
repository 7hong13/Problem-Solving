#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int nums[MAX];
int N;
bool visited[1001][2]; //0: neg + 0, 1: pos
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printSortingRes() {
    sort(nums, nums + N);
    for (int idx = 0; idx < N; idx++) {
        int num = nums[idx];
        if (num <= 0 && !visited[num * -1][0]) {
            cout << num << ' ';
            visited[num * -1][0] = true;
        }
        else if (0 < num && !visited[num][1]) {
            cout << num << ' ';
            visited[num][1] = true;
        }
    }
}

int main() {
    init();
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        cin >> nums[idx];
    }
    printSortingRes();
    return 0;
}