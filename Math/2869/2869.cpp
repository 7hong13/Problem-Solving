#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    long long a, b, v;
    cin >> a >> b >> v;
    v -= a;
    long long meter = a - b;
    long long day = v / meter;
    day = v % meter == 0 ? day + 1 : day + 2;
    cout << day << "\n";
    return 0;
}