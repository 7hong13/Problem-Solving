#include <iostream>
#include <cstring>
#define MAX 64
using namespace std;
int N;
int arr[MAX][MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void compressImg(int n, int x, int y) {
    if (n == 1) {
        cout << arr[y][x];
        return;
    }
    bool isZero = true;
    bool isOne = true;
    for (int row = y; row < n + y; row++) {
        for (int col = x; col < n + x; col++) {
            if (arr[row][col]) isZero = false;
            else isOne = false;
        }
    }
    if (isZero) cout << "0";
    else if (isOne) cout << "1";
    else {
        cout << "(";
        compressImg(n/2, x, y);
        compressImg(n/2, x + n/2, y);
        compressImg(n/2, x, y + n/2);
        compressImg(n/2,  x + n/2, y + n/2);
        cout << ")";
    }
}

int main() {
    init();
    cin >> N;
    for (int row = 0; row < N; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < N; col++) {
            arr[row][col] = s[col] - 48;
        }
    }
    compressImg(N, 0, 0);
    return 0;
}