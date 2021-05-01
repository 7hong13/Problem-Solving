#include <iostream>
#include <cmath>
using namespace std;
int N;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void towerOfHanoi(int n, int from, int by, int to) {
    if (n == 1) {
        cout << from << ' ' << to << "\n";
        return;
    }
    towerOfHanoi(n - 1, from, to, by);
    cout << from << ' ' << to << "\n";
    towerOfHanoi(n - 1, by, from, to);
}

int main() {
    init();
    cin >> N;
    int K = pow(2, N) - 1;
    cout << K << "\n";
    towerOfHanoi(N, 1, 2, 3);
    return 0;
}