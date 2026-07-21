#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
   ll n;
   cin >>n;
   ll a[n],s[n],sum=0;
   for(ll i=0;i<n;i++){
     cin >>a[i];
     sum+=a[i];
     if(i==0) s[i]=a[i];
     else s[i]=(s[i-1]+a[i]);
   }
   ll ans=10000000009;
   for(ll i=0;i<n-1;i++){
       ans=min(ans,abs(sum-2*s[i]));
   }
   cout<<ans<<endl;
   return 0;
}
