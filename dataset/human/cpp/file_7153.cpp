#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a[200005],b[200005];
ll ans=1000000000000000000;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
    }
    for(int i=1;i<n;i++){
        ans=min(ans,abs((b[n]-b[i])-b[i]));
    }
    cout<<ans<<endl;

}
