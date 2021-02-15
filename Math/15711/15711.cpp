#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2000000 //root of 4 * 10^12
using namespace std;
typedef long long ll;
bool isPrimeNum[MAX + 1]; //idx starts from 1
vector<int> primeNum;
ll A, B;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
    fill(isPrimeNum, isPrimeNum + MAX + 1, 1);
}

void checkPrimeNum() {
    for (int num = 2; num * num <= MAX; num++) {
        if (isPrimeNum[num]) {
            for (int idx = num * num; idx <= MAX; idx += num) {
                if (isPrimeNum[idx]) isPrimeNum[idx] = false;
            }
        } 
    }
    isPrimeNum[1] = false;
    for (int num = 2; num <= MAX; num++) {
        if (isPrimeNum[num]) primeNum.push_back(num);
    }
}

bool isDividable() {
    ll sum = A + B;
    if (sum < 4) return false;
    if (sum % 2 == 0) return true;
    //sum이 홀수 일 때 => sum =  2 + (sum - 2)
    sum -= 2;
    for (int idx = 0; idx < (int) primeNum.size() 
        && (ll) primeNum[idx] * primeNum[idx] <= sum; idx++) {
        if (sum % primeNum[idx] == 0) return false;
    }
    return true;
}

int main() {
    init();
    int T;
    cin >> T;
    checkPrimeNum();
    while (T--) {
        cin >> A >> B;
        bool ans = isDividable();
        ans == true ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}