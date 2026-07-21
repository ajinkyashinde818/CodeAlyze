#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> s(n);
    ll ans = 1e18;
    for(int i = 0;i < n;i ++){
        ll a;
        cin >> a;
        if(i==0)s[0]=a;
        else s[i] = s[i-1] + a;
    }
    for(int i = 0;i < n-1;i ++){
        if(abs((s[n-1]-s[i])-s[i])<ans) ans = abs((s[n-1]-s[i])-s[i]);
    }
    cout << ans << endl;
    return 0;
}
