#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin >> n;
    vector<ll> a;
    ll sum = 0;
    for(int i=0; i<n; i++){
        ll tmp; cin >> tmp;
        a.push_back(tmp);
        sum +=tmp;
    }
    ll x = 0;
    ll ans = 1000000000000000000LL;
    for(int i=0; i<n; i++){
        x +=a[i];
        if(i+1 < n){
            ans = min(ans, abs(sum - 2*x));
        }
    }
    cout << ans << endl;
    return 0;
}
