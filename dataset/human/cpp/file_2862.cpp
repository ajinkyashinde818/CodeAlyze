#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    bool flag = false;
    rep (i, n) {
        cin >> a[i];
        if (a[i] == 0) {
            flag = true;
        }
    }

    if (flag) {
        ll ans = 0;
        rep (i, n) {
            ans += abs(a[i]);
        }
        cout << ans << endl;
        exit(0);
    }
    sort(all(a));
    int idx = 0;
    ll ans = 0;
    while (idx + 1 < n) {
        ll p = a[idx];
        ll q = a[idx + 1];
        if (p < 0 && q < 0) {
            ans += -(p + q);
        } else if (p < 0) {
            ans += abs(p + q);
        } else {
                ans += p + q;
        }
        idx += 2;

    }
    if (n % 2 == 1) {
        ans += a[n - 1];
    }
    cout << ans << endl;
}
