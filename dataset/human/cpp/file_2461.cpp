#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    
    vector<ll> a(n);
    ll mn = mod;
    ll ans = 0;
    int cnt = 0;
    
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) cnt++;
        ans += abs(a[i]);
        mn = min(mn,abs(a[i]));
    }
    if(cnt%2 == 0) cout << ans << endl;
    else cout << ans-2*mn << endl;
    return 0;
}
