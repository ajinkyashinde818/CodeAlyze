#include<bits/stdc++.h>
using namespace std;

int n,r,g,b;
int ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>g>>b>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int l=n-i*r-j*g;
            if(l<0)continue;
            if(l%b==0)ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
