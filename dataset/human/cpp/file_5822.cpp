#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

struct P {
    bool operator<(const P& p) const {
        return x < p.x;
    }
    ll x;
    int v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll c;
    cin >> c;

    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].v;
    }
    sort(p.begin(), p.end());

    ll r = 0;
    vector<ll> a(n);
    for (int l = 0; l < 2; l++) {
        ll t = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += p[i].v;
            t = max(t, s - p[i].x);
            a[i] = t;
        }

        s = 0;
        for (int i = n - 1; i > 0; i--) {
            s += p[i].v;
            t = max(t, s - (c - p[i].x) * 2 + a[i - 1]);
        }

        r = max(r, t);

        if (l == 0) {
            for (int i = 0; i < n; i++) {
                p[i].x = c - p[i].x;
            }
            reverse(p.begin(), p.end());
        }
    }

    cout << r << endl;

    return 0;
}
