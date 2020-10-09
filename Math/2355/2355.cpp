#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    long long a, b, result;
    cin >> a >> b;
    if (a >= 0 && b >= 0 && a <= b) {
        result = (b * (b + 1) / 2) - ((a - 1) * a / 2);
    }
    else if (a >= 0 && b >= 0 && a > b) {
        result = (a * (a + 1) / 2) - ((b - 1) * b / 2);
    }
    else if (a < 0 && b >= 0) {
        result = (b * (b + 1) / 2) - (-a * (-a + 1) / 2);
    }
    else if (a >= 0 && b < 0) {
        result = (a * (a + 1) / 2) - (-b * (-b + 1) / 2);
    }
    else if (a < 0 && b < 0 && a <= b) { 
        result = (-a * (-a + 1) / 2 - (-b - 1) * (-b) / 2) * -1;
    }
    else if (a < 0 && b < 0 && a > b) { // -3 -5
        result = (-b * (-b + 1) / 2 - (-a - 1) * (-a) / 2 ) * -1;
    }
    cout << result << "\n";
    
    return 0;
}