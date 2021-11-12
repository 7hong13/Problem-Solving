#include <iostream>
using namespace std;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printDestRoomNumber() {
    int H, W, N;
    cin >> H >> W >> N;
    int y = (N - 1) % H + 1;
    int x = (N - 1) / H + 1;
    cout << y * 100 + x << "\n";
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        printDestRoomNumber();
    }
    return 0;
}