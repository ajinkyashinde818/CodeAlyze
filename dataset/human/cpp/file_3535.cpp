#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n;
  cin >>n;
  ll a[n],ans=0,b[n],c=0;
  for(ll i=0;i<n;i++) {
    cin >>a[i];
    ans+=abs(a[i]);
    if(a[i]<0) c++;
    b[i]=abs(a[i]);
  }
  sort(b,b+n);
  if(c%2==0) cout <<ans<<endl;
  else cout <<ans-b[0]*2<<endl;
}
