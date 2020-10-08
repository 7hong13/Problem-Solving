#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int max = -9999999, min = 9999999;
    while (n--) {
        int x;
        cin >> x;
        if (x > max) {
            max = x;
        }
        if (x < min) {
            min = x;   
        }
    }
    cout << min << " " << max << "\n";
    return 0;
}