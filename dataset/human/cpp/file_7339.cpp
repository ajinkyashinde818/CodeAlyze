#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    int n;
    cin >> n;
    vl a(n,0);
    rep(i,n) cin >> a[i];
    for(int i = 1; i < n; i++) a[i] += a[i-1];
    ll ans = LINF;
    rep(i, n-1){
        ll temp = abs(a[i] - (a[n-1] - a[i]));
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
