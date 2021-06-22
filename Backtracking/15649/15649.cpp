#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool arr[9];
vector<int> v;
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

void seq(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int j = 1; j <= N; j++) {
		if (arr[j]) continue;
		arr[j] = true;
		v.push_back(j);
		seq(cnt + 1);
		v.pop_back();
		arr[j] = false;
	}
}

int main() {
    init();
    cin >> N >> M;
    for (int idx = 1; idx <= N; idx++) {
		arr[idx] = true;
		v.push_back(idx);
		seq(1);
		arr[idx] = false;
		v.pop_back();
	}
    return 0;
}