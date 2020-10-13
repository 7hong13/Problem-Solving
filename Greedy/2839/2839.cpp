#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int n, answer = -1;
    cin >> n;
    if (n < 5) {
        answer = n == 3 ? 1 : -1;
    }
    else if (n % 5 == 0) {
        answer = n / 5;
    }
    else {
        int savedN = n;
        int quotient = 0;
        while (savedN > 0) {
            if ((n - quotient * 5) % 3 == 0) {
                answer = quotient + (n - quotient * 5) / 3;
            }
            savedN -= 5;
            quotient++; 
        }
    }
    cout << answer << "\n";
    return 0;
}