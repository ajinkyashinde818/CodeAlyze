#include <bits/stdc++.h>
using namespace std;
int main() {
    int r,g,b,n,ans=0;
    cin>>r>>g>>b>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) {
            int tmp=n-r*i-g*j;
            if(tmp>=0 &&tmp%b==0)ans++;
        }
    }
    cout<<ans<<endl;
}
