#include <iostream>
#include <algorithm>
using namespace std;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void printWhetherRightTrianlge() {
    int a, b, c;
    cin >> a >> b >> c;
    while (!(a == 0 && b == 0 && c == 0)) {
        int squares[] = {a * a, b * b, c * c};
        sort(squares, squares + 3);
        squares[0] + squares[1] == squares[2] ? cout << "right\n" : cout << "wrong\n";
        cin >> a >> b >> c;
    }
}

int main() {
    init();
    printWhetherRightTrianlge();
}