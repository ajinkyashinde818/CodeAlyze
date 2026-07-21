#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll r,g,b,n;
  cin >> r>>g>>b>>n;
  ll ans=0;
  for (ll i=0;i<=n/r;i++) {
    for (ll j=0;j<=(n-r*i)/g;j++) {
      if ((n-r*i-g*j)%b==0) {
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
