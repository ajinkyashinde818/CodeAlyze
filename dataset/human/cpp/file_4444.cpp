#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    int sum = 0;
    for (int i = 0; i < n; ++i) sum ^= a[i];
    a.push_back(sum);
    sum = 0;
    for (int i = 0; i < n; ++i) sum ^= b[i];
    b.push_back(sum);
    if (multiset<int>(a.begin(), a.end()) != multiset<int>(b.begin(), b.end())) {
        puts("-1");
        return 0;
    }

    if (a == b) {
        puts("0");
        return 0;
    }

    vector<int> v;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (a[i] != b[i] || i == n) {
            v.push_back(a[i]);
            v.push_back(b[i]);
            ans += i < n;
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    vector<int> uf(v.size());
    iota(uf.begin(), uf.end(), 0);

    function<int(int)> Find = [&](int x) {
        if (x == uf[x]) return x;
        return uf[x] = Find(uf[x]);
    };

    auto Merge = [&](int x, int y) {
        uf[Find(x)] = Find(y);
    };

    for (int i = 0; i <= n; ++i) {
        if (a[i] != b[i] || i == n) {
            int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            int y = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
            Merge(x, y);
        }
    }
    for (int i = 0; i < v.size(); ++i) ans += Find(i) == i;
    printf("%d\n", ans - 1);
}
