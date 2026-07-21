#include <bits/stdc++.h>

constexpr int N = 1e5;

int n;
int a[N + 1], b[N + 1], c[N + 1], d[N + 1];

int f[N + 1];
int find(int x) {
    while (x != f[x])
        x = f[x] = f[f[x]];
    return x;
}
bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return 0;
    f[x] = y;
    return 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[n] ^= a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        b[n] ^= b[i];
    }
    
    std::copy(a, a + n + 1, c);
    std::copy(b, b + n + 1, d);
    std::sort(c, c + n + 1);
    std::sort(d, d + n + 1);
    if (!std::equal(c, c + n + 1, d)) {
        std::cout << -1 << "\n";
        return 0;
    }
    
    for (int i = 0; i <= n; ++i)
        f[i] = i;
    int ans = 0, cnt = 0;
    std::map<int, int> id;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;
        ++ans;
        if (!id.count(a[i]))
            id[a[i]] = cnt++;
        if (!id.count(b[i]))
            id[b[i]] = cnt++;
        if (merge(id[a[i]], id[b[i]]))
            --ans;
    }
    
    ans += cnt;
    ans -= id.count(a[n]);
    
    std::cout << ans << "\n";
    
    return 0;
}
