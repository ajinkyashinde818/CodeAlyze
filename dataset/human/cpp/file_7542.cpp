#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+16;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        a[i] += a[i-1];
    }
    ll ans = INF;
    for(int i = 1; i < n; i++){
        ll x = a[n] - a[i];
        ll y = a[i];
        ans = min(ans, abs(x - y));
    }
    cout << ans << endl;
    return 0;
}
