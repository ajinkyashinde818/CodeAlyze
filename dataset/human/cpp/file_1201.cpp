#include "bits/stdc++.h"
using namespace std;
int main(){
    int r,g,b,n,now,ans=0;
    cin >> r>>g>>b>>n;
    for(int i=0;i<=n/r;i++){
        for(int j=0;j<=n/g;j++){
            now=n-i*r-j*g;
            if(now%b==0&&now>=0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
