#include<iostream>
#include<vector>
using ll = long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(i) v[i]=v[i-1]+a;
        else v[i]=a;
    }

    ll ans=1e10;
    for(int i=0;i<n-1;i++){
        ll x=v[i];
        ll y=v[n-1]-v[i];
        ans=min(ans,abs(x-y));
    }
    cout<<ans<<endl;
}
