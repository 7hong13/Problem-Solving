#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
int n;
bool isPrimeAndOdd[MAX + 1]; //idx starts from 1
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(isPrimeAndOdd, isPrimeAndOdd + MAX + 1, 1);
}

void checkPrimeNums() {
    for (int num = 2; num * num <= MAX; num++) {
        if (isPrimeAndOdd[num]) {
            for (int idx = num * num; idx <= MAX; idx += num) {
                if (isPrimeAndOdd[idx]) isPrimeAndOdd[idx] = false;
            }
        }
    }
    isPrimeAndOdd[1] = false;
    isPrimeAndOdd[2] = false;
}

void printPrimeNumPair() {
    int a = -1, b = -1;
    for (int idx = 3; idx < n; idx++) {
        if (!isPrimeAndOdd[idx]) continue;
        if (isPrimeAndOdd[n - idx]) {
            a = idx;
            b = n - idx;
            break;
        }
    }
    if (a == -1 && b == -1) cout << "Goldbach's conjecture is wrong.\n";
    else cout << n << " = " << a << " + " << b << "\n";
}

int main() {
    init();
    checkPrimeNums();
    cin >> n;
    while (n) {
        printPrimeNumPair();
        cin >> n;
    }
    return 0;
}