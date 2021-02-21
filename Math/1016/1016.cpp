#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;
typedef long long ll;
bool isDividable[MAX + 1];
ll mn, mx;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void checkDividable() {
    for (ll idx = 2; idx * idx <= mx; idx++) {
        ll square = idx * idx;
        ll quotient = mn / square;
        if (mn % square != 0) quotient++; 
        while (square * quotient <= mx) {
            ll num = square * quotient;
            if (!isDividable[num - mn]) isDividable[num - mn] = true;
            quotient++;
        }
    }
}

ll countNonSquareDividable() {
    ll cnt = 0;
    for (int idx = 0; idx < mx - mn + 1; idx++) {
        if (!isDividable[idx]) cnt++;
    }
    return cnt;
}

int main() {
    init();
    cin >> mn >> mx;
    checkDividable();
    ll ans = countNonSquareDividable();
    cout << ans;
    return 0;
}