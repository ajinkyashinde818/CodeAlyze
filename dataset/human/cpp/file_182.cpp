#include <bits/stdc++.h>
using namespace std;

int main() {
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans = 0;
    for(int i=0;i<=n;i++) {
        for(int j=0; j<=n; j++) {
            int x = r*i+j*g;
            if(x>n) break;
            if((n-x)%b==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
