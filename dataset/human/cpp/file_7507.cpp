#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll sunuke = a[0], ans = abs(sum - 2 * sunuke);
    for(ll i = 1; i < n - 1; i++){
        sunuke += a[i];
        ans = min(ans, abs(sum - 2 * sunuke));
    }
    cout << ans << endl;
}
