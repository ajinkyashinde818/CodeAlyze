#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;
 
int main() {
  ll n;
  cin >> n;
  vector<ll>a(n);
  ll ans =0; 
  ll count = 0;
  ll mini=10e9;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i]<0){
      count++;
      a[i]*=-1;
    }
    ans+=a[i];
    mini=min(mini,a[i]);
  }
  
  if(mini==0 || count%2==0) cout << ans << endl;
  else cout << ans-mini*2 << endl;
  
  
  return 0;
  
  
}
