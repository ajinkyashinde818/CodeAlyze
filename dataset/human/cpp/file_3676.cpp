#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=(1e9+7);
const ll inf=(1ll<<61);
const int MX=3e5+9;
int n;
ll a[MX];
ll ans=0,sum=0,mx=100000000000,ans1=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<0)sum++;
        ans+=abs(a[i]);
        mx=min(mx,abs(a[i]));
    }
    if(sum%2==0){
        cout<<ans<<endl;
    }
    else cout<<ans-2*mx<<endl;
}
