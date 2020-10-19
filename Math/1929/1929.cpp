#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000000
bool numbers[MAX];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    memset(numbers, 0, sizeof(numbers));
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
    return 0;
}