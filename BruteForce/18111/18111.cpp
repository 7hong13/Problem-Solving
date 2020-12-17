#include <iostream>
using namespace std;
int N, M;
long long B, minTime = 999999999999999, minHeight;
int ground[501][501];
void init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findMinTimeAndHeight() {
    long long under, over, blocks;
    for (int h = 0; h <= 256; h++) {
        under = over = 0;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (ground[row][col] < h) {
                    under += h - ground[row][col];
                }
                else if (ground[row][col] > h) {
                    over += ground[row][col] - h;
                }
            }
        }
        blocks = over + B;
        if (blocks < under) continue;
        long long time = under + over * 2;
        if (time <= minTime) {
            minTime = time;
            minHeight = h;
        }
    }
}

int main() {
    init();
    cin >> N >> M >> B;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> ground[row][col];
        }
    }
    findMinTimeAndHeight();
    cout << minTime << ' ' << minHeight;
    return 0;
}