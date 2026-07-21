#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    int r,g,b,n; cin >>r>>g>>b>> n;
    ll ans = 0;
    for(int i=0; i*r<=n; i++){
        for(int j=0; i*r+j*g<=n; j++){
            if((n-(i*r+j*g))%b==0)
                ans ++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
