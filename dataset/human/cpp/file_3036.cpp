#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;cin>>n;
  vector<int64_t> a(n);
  int64_t ans = 0,mn=1e9+1,cnt=0;
  for(int i=0;i<n;++i) {
    cin>>a[i];
    ans += abs(a[i]);
    mn = min(abs(a[i]),mn);
    if(a[i]<0) ++cnt;
  }
  
  if (cnt%2==1) ans -= 2*mn;
  cout<<ans<<endl;

}
