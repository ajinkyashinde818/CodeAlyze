#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, x, tot, ans, a[maxn], b[maxn], c[maxn], d[maxn], fa[maxn];
bool chk[maxn];
map<int, int> mp;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n), n++;
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i], x ^= a[i];
    }
    a[n] = c[n] = x, x = 0;
    sort(c + 1, c + n + 1);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b[i]);
        d[i] = b[i], x ^= b[i];
    }
    b[n] = d[n] = x;
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        if (c[i] ^ d[i]) printf("-1\n"), exit(0);
        if (!mp.count(c[i])) mp[c[i]] = ++tot;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]], b[i] = mp[b[i]];
        if (a[i] == b[i]) continue;
        if (i < n) ans++;
        int u = find(a[i]), v = find(b[i]);
        fa[u] = v, chk[a[i]] = chk[b[i]] = 1;
    }
    if (!ans) printf("0\n"), exit(0);
    chk[a[n]] = chk[b[n]] = 1;
    for (int i = 1; i <= tot; i++) {
        if (chk[i] && i == find(i)) ans++;
    }
    printf("%d\n", ans - 1);
    return 0;
}
