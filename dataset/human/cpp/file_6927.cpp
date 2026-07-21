#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll po(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b % 2) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

ll f[2000006], g[2000006];

void comb() {
    f[0] = 1;
    for (int i = 1; i <= 2000000; i++) f[i] = f[i - 1] * i % mod;
    g[2000000] = 407182070;
    for (int i = 1999999; i >= 0; i--) g[i] = g[i + 1] * (i + 1) % mod;
}

int p[200005];

int root(int x) {return p[x] < 0 ? x : p[x] = root(p[x]);}

void mer(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, a[200005] = {}, b[200005] = {}, e[200005] = {}, x[200005] = {}, y[200005] = {}, f = 0, g = 0, h[200005] = {};
    pii d[200005] = {}, z[200005] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], h[a[i]]++, d[a[i]].first++;
    for (int i = 0; i < n; i++) cin >> b[i], e[b[i]]++;
    for (int i = 1; i <= n; i++) d[i].second = i;
    sort(d + 1, d + n + 1);
    for (int i = n; i; i--) {
        if (d[i].first + e[d[i].second] > n) {
            cout << "No";
            return 0;
        }
        for (int j = f; j < min(n, f + d[i].first); j++) x[j] = d[i].second;
        f += d[i].first;
        for (int j = f; j < min(n, f + e[d[i].second]); j++) y[j] = d[i].second;
        f += e[d[i].second];
        if (f >= n) {
            g = d[i].second;
            break;
        }
    }
    multiset<int> s, t;
    for (int i = 0; i < n; i++) h[x[i]]--, e[y[i]]--;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < h[i]; j++) s.insert(i);
        for (int j = 0; j < e[i]; j++) t.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (!x[i]) {
            x[i] = *s.begin();
            s.erase(s.begin());
        }
        if (!y[i]) {
            if (e[g]) y[i] = g, e[g]--, t.erase(t.find(g));
            else y[i] = *t.begin(), t.erase(t.begin());
        }
    }
    for (int i = 0; i < n; i++) z[i].first = x[i], z[i].second = y[i];
    sort(z, z + n);
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << z[i].second << ' ';
}
