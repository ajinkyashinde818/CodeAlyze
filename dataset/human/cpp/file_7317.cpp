#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin>>n;
  ll a[200005];
  ll s[200005];
  ll sum=0;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    sum+=a[i];
    s[i]=sum;
  }
  ll ans=1e18;
  for (int i=0; i<n-1; i++) {
    ans=min(ans,abs(sum-s[i]*2));
  }
  cout<<ans<<endl;
  return 0;
}
