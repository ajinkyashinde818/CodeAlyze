#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a (n);
    ll minus = 0;
    vector<ll> rev (n);
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        a.at(i) = x;
        if(x < 0){
            x = -x;
            minus++;
        }
        rev.at(i) = x;
        ans += x;
    }
    sort(rev.begin(),rev.end());
    if(minus%2 == 1) ans -= rev.at(0)*2;
    cout << ans << endl;
}
