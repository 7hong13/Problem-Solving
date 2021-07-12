#include <iostream>
#include <algorithm>
#define MAX 100000
#define INF 1111111111
using namespace std;
typedef long long ll;
int N, M;
int nums[MAX + 1];
int minTree[3 * MAX], maxTree[3 * MAX];
void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(0);
}

// node: 세그먼트 트리 노드 번호
// node가 담당하는 범위가 start ~ end
ll setMinTree(int node, int start, int end) {
    if (start == end) {
        return minTree[node] = nums[start];;
    } 
    return minTree[node] = min(setMinTree(node * 2, start, (start + end) / 2), 
        setMinTree(node * 2 + 1, (start + end) / 2 + 1, end));
}

ll setMaxTree(int node, int start, int end) {
    if (start == end) {
        return maxTree[node] = nums[start];;
    } 
    return maxTree[node] = max(setMaxTree(node * 2, start, (start + end) / 2), 
        setMaxTree(node * 2 + 1, (start + end) / 2 + 1, end));
}

ll searchMinTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    }
    if (left <= start && end <= right) {
        return minTree[node];
    }
    return min(searchMinTree(node * 2, start, (start + end) / 2, left, right), 
        searchMinTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll searchMaxTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return -INF;
    }
    if (left <= start && end <= right) {
        return maxTree[node];
    }
    return max(searchMaxTree(node * 2, start, (start + end) / 2, left, right), 
        searchMaxTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}


int main() {
    init();
    cin >> N >> M;
    for (int idx = 1; idx <= N; idx++) {
        cin >> nums[idx];
    }

    setMinTree(1, 1, N);
    setMaxTree(1, 1, N);

    while (M--) {
        int left, right;
        cin >> left >> right;
        cout << searchMinTree(1, 1, N, left, right) << ' ' << searchMaxTree(1, 1, N, left, right) << "\n";
    }

    return 0;
}
