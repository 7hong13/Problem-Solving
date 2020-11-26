#include <iostream>
using namespace std;
long long n;
int l;
// n = x + (x + 1) + ... + (x + L - 1)
// n = L * x + L * (L - 1) / 2
// x = (n - L * (L - 1) / 2 ) / L
int findSequence() {
    while (l <= 100) {
        int subSum = l * (l - 1) / 2;
        if ((n - subSum) % l == 0) {
            return (n - subSum) / l;
        }
        l++;
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> n >> l;
    int answer = findSequence();
    if (answer < 0) {
        cout << "-1\n";
    }
    else {
        for (int start = 0; start < l; start++) {
            cout << answer++ << " "; 
        }
    }
    return 0;
}