#include <iostream>
using namespace std;
int n1, n2;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void findGcdAndLcm() {
    int div = n1 < n2 ? n1 : n2;
    int gcd = 1;
    while (1 < div) {
        if (n1 % div == 0 && n2 % div == 0) {
            n1 /= div;
            n2 /= div;
            gcd *= div;
            div = n1 < n2 ? n1 : n2;
            continue;
        }
        div--;
    }
    int lcm = gcd * n1 * n2;
    cout << gcd << "\n" << lcm;
}

int main() {
    init();
    cin >> n1 >> n2;
    findGcdAndLcm();
    return 0;
}