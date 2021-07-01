#include <iostream>
using namespace std;
int N, M;
int arr[9]; //idx starts from 1
bool visited[9];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void seq(int cnt) {
	if (cnt == M) {
		for (int idx = 0; idx < cnt; idx++) {
			cout << arr[idx] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int idx = 1; idx <= N; idx++) {
		if (!visited[idx]) {
			visited[idx] = true;
			arr[cnt] = idx;
			seq(cnt + 1);
			visited[idx] = false;
		}
	}
}

int main() {
    init();
    cin >> N >> M;
	seq(0);
    return 0;
}