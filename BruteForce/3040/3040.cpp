#include <iostream>
using namespace std;
int height[9];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void find7Dwarfs(int sum) {
    for (int idx1 = 0; idx1 < 8; idx1++) {
        bool loopEnd = false;
        for (int idx2 = idx1 + 1; idx2 < 9; idx2++) {
            int h1 = height[idx1], h2 = height[idx2];
            if (sum - (h1 + h2) == 100) {
                height[idx1] = height[idx2] = -1;
                loopEnd = true;
                break;
            }
        }
        if (loopEnd) break;
    }
    for (int idx = 0; idx < 9; idx++) {
        if (height[idx] < 0) continue;
        cout << height[idx] << "\n";
    }
}

int main() {
    init();
    int sum = 0;
    for (int idx = 0; idx < 9; idx++) {
        cin >> height[idx];
        sum += height[idx];
    }
    find7Dwarfs(sum);
    return 0;
}