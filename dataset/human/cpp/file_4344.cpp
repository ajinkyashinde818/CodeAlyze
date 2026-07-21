#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
static const int MAXN = 1e5 + 4;

int n;
int a[MAXN], b[MAXN];

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void merge(int u, int v) { u = root(u), v = root(v); if (u != v) p[u] = v; }
}

inline int min_rots(int n, int *a, int *b)
{
    int id_tot = 0;
    std::map<int, int> id;
    dsu::init(n);
    for (int i = 0; i < n; ++i) if (b[i] != a[i]) {
        if (id.find(a[i]) == id.end()) id[a[i]] = id_tot++;
        if (id.find(b[i]) == id.end()) id[b[i]] = id_tot++;
        dsu::merge(id[a[i]], id[b[i]]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) if (b[i] != a[i]) ++ans;
    for (int i = 0; i < id_tot; ++i) if (dsu::root(i) == i) ++ans;
    return ans;
}

int main()
{
    scanf("%d", &n);
    int xor_sum = 0;
    for (int i = 0; i < n; ++i) { scanf("%d", &a[i]); xor_sum ^= a[i]; }
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    std::multiset<int> as;
    for (int i = 0; i < n; ++i) as.insert(a[i]);
    bool has_sum = false;
    for (int i = 0; i < n; ++i) {
        auto p = as.find(b[i]);
        if (p == as.end()) {
            if (b[i] == xor_sum && !has_sum) {
                has_sum = true;
            } else {
                puts("-1"); return 0;
            }
        } else {
            as.erase(p);
        }
    }

    if (has_sum) {
        int idx = -1;
        for (int i = 0; i < n; ++i)
            if (b[i] == xor_sum && a[i] != b[i]) { idx = i; break; }
        if (idx == -1)
            for (int i = 0; i < n; ++i) if (b[i] == xor_sum) { idx = i; break; }
        b[idx] = *as.begin();
        int ans = min_rots(n, a, b);
        printf("%d\n", ans == 0 ? 1 : ans - 1);
    } else {
        bool save = false;
        for (int i = 0; i < n; ++i)
            if (b[i] == xor_sum && b[i] != a[i]) save = true;
        printf("%d\n", min_rots(n, a, b) - save);
    }

    return 0;
}
