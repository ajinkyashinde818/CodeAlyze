#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    ll a[200050]={};
    cin >> n;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll ans = 1e14;
    for(ll i = 1;i < n;i++){
        ll cand = llabs(a[n] - a[i] - a[i]);
        ans = min(ans, cand);
    }
    cout << ans << endl;
}
