#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,ans=2e9;
  cin >> n;
  ll a[n],b[n+1];
  b[0]=0;
  for(ll i=0;i<n;i++){
    cin >> a[i];
    b[i+1] = b[i]+a[i];
  }
  for(ll i=1;i<n;i++){
    ans = min(ans,abs(b[n]-2*b[i]));
  }
  cout << ans << endl;
}
