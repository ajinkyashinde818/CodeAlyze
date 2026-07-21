#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    ll s[200010];
    s[0]=0;
    for(int i=1;i<=n;i++){
        ll a; cin>>a;
        s[i]=s[i-1]+a;
    }
    ll ans=2e9+10;
    for(int i=1;i<=n-1;i++){
        ans=min(ans,abs(2*s[i]-s[n]));
    }
    cout<<ans<<endl;
}
