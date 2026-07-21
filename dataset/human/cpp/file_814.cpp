#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll r,g,b,n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    for (ll i = 0; i <= n; i++){
        for (ll j = 0; j <= n; j++){
            ll x = n - (r*i + g*j);
            if (x >= 0 && x%b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}
