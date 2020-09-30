#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Member {
    int num;
    int age;
    string name;
};
bool compare(Member member1, Member member2) {
    if (member1.age == member2.age) return member1.num < member2.num;
    return member1.age < member2.age;
}
Member arrForSorting[100001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int idx = 0; idx < n ; idx++) {
        cin >> arrForSorting[idx].age >> arrForSorting[idx].name;
        arrForSorting[idx].num = idx;
    }
    sort(arrForSorting, arrForSorting + n, compare);
     for (int idx = 0; idx < n ; idx++) {
        cout << arrForSorting[idx].age << " " << arrForSorting[idx].name <<"\n";
    }
    return 0;
}