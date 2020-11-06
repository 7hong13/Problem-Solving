#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000000
bool numbers[MAX];
int m, n;
void findPrimeNumber() {
    for (int idx = 2; idx * idx <= MAX && idx <= n; idx++) {
		if (!numbers[idx]) {
			for (int sieve = idx * idx; sieve <= MAX && sieve <= n; sieve += idx)
				numbers[sieve] = true;
		}
	}
	numbers[1] = true;
	for (int num = m; num <= n; num++)
		if (!numbers[num]) {
            cout << num << "\n";
        }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    memset(numbers, 0, sizeof(numbers));
    findPrimeNumber();
    return 0;
}