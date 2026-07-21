#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=100000000000000000;

ll min(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}

int main(){
    ll n;cin>>n;
    ll a[n];
    ll sum=0;
    ll mini=inf;
    ll c=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            c++;
        }
        sum=sum+abs(a[i]);
        mini=min(mini,abs(a[i]));
    }
    if(c%2==1){
        cout<<sum-2*mini<<endl;
    }else{
        cout<<sum<<endl;
    }
    
    return 0;
}
