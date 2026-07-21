#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 50;

int las, n, m, ans, size[N], vis[N], a[N], b[N], c[N], d[N], f[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int u, int v) {
    if(u == v) return ;
    // cout << "Add=" << u << ' ' << v << '\n';
    f[u] = v, size[v] += size[u];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", a + i), m ^= a[i], c[i] = a[i], f[i] = i;
    f[n + 1] = n + 1, las = m;
    c[++n] = a[n] = m, m = 0;
    for(int i = 1; i < n; i++) 
        scanf("%d", b + i), m ^= b[i], d[i] = b[i];
    d[n] = b[n] = m;
    sort(c + 1, c + 1 + n), sort(d + 1, d + 1 + n);
    for(int i = 1; i <= n; i++) {
        if(c[i] != d[i]) return 0 * printf("-1\n");
    }
    int len = unique(c + 1, c + 1 + n) - c - 1;
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(c + 1, c + 1 + len, a[i]) - c;
        b[i] = lower_bound(c + 1, c + 1 + len, b[i]) - c;
        if(a[i] != b[i] && i < n) size[b[i]] ++;
    }
    m = las;
    int idx = -1, fuck = lower_bound(c + 1, c + 1 + len, m) - c;
    // cout << fuck << ' ' << m << '\n';
    // for(int i = 1; i <= n; i++) cout << b[i] << ' '; puts("");
    for(int i = 1; i < n; i++) {
        if(a[i] != b[i]) {
            vis[a[i]] = vis[b[i]] = 1;
            if(b[i] == fuck) idx = i;
            // cout << a[i] << ' ' << b[i] << '\n';
            merge(find(a[i]), find(b[i]));
        }
    } 
    // cout << idx << '\n';
    if(idx > 0) ans --;
    for(int i = 1; i <= n; ++i) 
        if(find(i) == i && size[i] > 0) 
            ans += size[i] + 1;
    cout << ans << '\n';
    return 0;
}
