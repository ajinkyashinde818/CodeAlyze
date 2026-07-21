#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ll b,c,d,e,k,l,m,n,o=0,p=-1,q,x,y,z,max1=0,ans=0,min1=1000000000;
    string s,t,u;
    cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) {
        cin>>a[i];
        ans+=max(a[i],a[i]*p);
        if (a[i]<0) {
            o++;
        }
        min1=min(min1,max(a[i],a[i]*p));
    }
    if (o%2==1) {
        ans-=min1*2;
    }
    
    cout<<ans<<endl;
}
