#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
    ll r,g,b,n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    for(int i=0;i<=n;++i){
        ll val = n - i*r;
        if(val < 0) break;
        for(int j=0;j<=n;++j){
            ll temp = val - j*g;
            if(temp < 0) break;
            if(temp%b==0) ans++;
        }
    }
    cout << ans << endl;
}
