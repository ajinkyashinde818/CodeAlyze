#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> a(n);
  long long sum=0;
  for(int i=0;i<n;++i) cin >> a[i],sum+=a[i];
  long long tmp=a[0]; sum-=a[0];
  long long ans=abs(sum-tmp);
  for(int i=1;i<n-1;++i){
    tmp+=a[i]; sum-=a[i];
    ans=min(ans,abs(sum-tmp));
  }
  cout << ans << endl;
  
  return 0;
}
