#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    ll ans=0;
    int count=0;
    ll MIN=10000000000;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=abs(a[i]);
        MIN=min(MIN,abs(a[i]));
        if(a[i]<0) count++;
    }
    if(count%2==0) cout<<ans<<endl;
    else cout<<ans-MIN*2<<endl;
}
