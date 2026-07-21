#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll r,g,b,n;
    cin >> r >> g >> b >> n;
    ll ans=0;
    ll sum=0;
    while(sum<=n){
        ll copy=sum;
        while(copy<=n){
            if((n-copy)%b==0){
                ans++;
            }
            copy+=g;
        }
        sum+=r;
    }
    cout << ans << endl;
}
