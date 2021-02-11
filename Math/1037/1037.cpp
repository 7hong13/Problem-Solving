#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;
int num, divisors[MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

int findIntegerN() {
    sort(divisors, divisors + num);
    return divisors[0] * divisors[num - 1];
}

int main() {
    init();
    cin >> num;
    for (int idx = 0; idx < num; idx++) {
        cin >> divisors[idx];
    }
    int N = findIntegerN();
    cout << N;
    return 0;
}