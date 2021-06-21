#include <iostream>
#include <algorithm>
using namespace std;
int height[9], sum = 0;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void print7Dwarfs() {
    bool loopEnd = false;
    for (int idx1 = 0; idx1 < 8; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < 9; idx2++) {
            int subSum = height[idx1] + height[idx2];
            if (sum - subSum == 100) {
                height[idx1] = height[idx2] = -1;
                loopEnd = true;
                break;
            }
        }
        if (loopEnd) break;
    }
    sort(height, height + 9);
    for (int idx = 2; idx < 9; idx++) {
        cout << height[idx] << "\n";
    }
}

int main() {
    init();
    for (int idx = 0; idx < 9; idx++) {
        cin >> height[idx];
        sum += height[idx];
    }
    print7Dwarfs();
    return 0;
}