#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll values[100001];
bool compare(ll value1, ll value2) {
    return abs(value1) < abs(value2);
}
int value1, value2, n;
void findClosestValues() {
    value1 = values[0];
    value2 = values[1];
    for (int idx = 1; idx < n - 1; idx++) {
        ll sum = values[idx] + values[idx + 1];
        if (abs(sum) < abs(value1 + value2)) {
            value1 = values[idx];
            value2 = values[idx+1];
        }
    }
    if (value1 <= value2) {
        cout << value1 << " " << value2 << "\n";
    }
    else {
        cout << value2 << " " << value1 << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int idx = 0; idx < n; idx++) {
        cin >> values[idx];
    }
    sort(values, values + n ,compare);
    findClosestValues();
    return 0;
}