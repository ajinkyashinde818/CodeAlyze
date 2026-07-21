#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

const int Max = 100033;
int n, a[Max], b[Max], c[Max], d[Max], fa[Max], cnt, ans;
map<int, int> id;
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = c[i] = read();
    for (int i = 1; i <= n; i++) b[i] = d[i] = read();
    for (int i = 1; i <= n; i++) {
        c[n + 1] = a[n + 1] ^= a[i];
        d[n + 1] = b[n + 1] ^= b[i];
    }
    n++;
    sort(c + 1, c + n + 1), sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++)
        if (c[i] != d[i]) {
            puts("-1"); return 0;
        }
    for (int i = 1; i < n; i++)
        if (a[i] != b[i]) {
            ans++;
            if (!id[a[i]]) id[a[i]] = ++cnt;
            if (!id[b[i]]) id[b[i]] = ++cnt;
        }
    if (!id[a[n]]) id[a[n]] = ++cnt;
    if (!id[b[n]]) id[b[n]] = ++cnt;
    if (!ans) { puts("0"); return 0; }
    for (int i = 1; i <= cnt; i++) fa[i] = i;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            fa[find(id[a[i]])] = find(id[b[i]]);
    for (int i = 1; i <= cnt; i++)
        if (find(i) == i) ans++;
    cout << ans - 1 << endl;
    return 0;
}
