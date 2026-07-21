//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int N = 1e5 + 5;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i + 1 < n; i++) {
        if (-a[i] - a[i + 1] > a[i] + a[i + 1]) {
            a[i] = -a[i];
            a[i + 1] = -a[i + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans;
    return 0;
}
