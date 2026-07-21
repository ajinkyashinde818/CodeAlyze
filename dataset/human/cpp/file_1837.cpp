#include <bitset>
#include <cstdio>
#include <list>

using namespace std;

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    bitset<200001> b;
    list<int> v;
    for (int i = 0; i < m; ++i) {
        int e;
        scanf("%d", &e);
        v.push_front(e);
    }

    for (auto&& i : v) {
        if (b[i]) {
        } else {
            printf("%d\n", i);
            b[i] = true;
        }
    }
    for (auto i = 1; i <= n; ++i) {
        if (!b[i]) {
            printf("%d\n", i);
        }
    }
}
