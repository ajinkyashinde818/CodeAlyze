#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 100000000;

ll i,j,k;

int main(){
    ll n;cin>>n;
    vector<ll> a(n);for(i=0;i<n;i++){cin>>a[i];}

    sort(a.begin(),a.end());

    for(i=0;i<n-1;i++){
        if(a[i]+a[i+1]<0){a[i]*=(-1);a[i+1]*=(-1);}
    }

    ll sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }

    cout<<sum<<endl;
    return 0;
}
