#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int r,g,b,n;cin >> r >> g >> b >> n;
    ll ans=0;
    for(int i = 0; i < 3001; i++) {
        for(int j = 0; j < 3001; j++) {
            if(n-i*r-j*g>=0 && (n-i*r-j*g)%b==0){
                ans++;
            }
        }
    }
 cout << ans << endl;
    return 0;
}
