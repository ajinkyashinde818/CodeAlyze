#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,a[200010];
  cin>>n;
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=1;i<n;++i)a[i]+=a[i-1];

  long long ans=2e9;
  for(int i=0;i<n-1;++i){
    ans=min(ans,abs(a[i]*2-a[n-1]));
  }
  cout << ans << endl;
  return 0;
}
