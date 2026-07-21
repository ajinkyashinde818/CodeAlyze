#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  long long ans=1e15,t=0;
  for(int i=0;i<n-1;i++){
    t+=a[i];
    ans=min(ans,abs(t-(sum-t)));
  }
  cout << ans << endl;
}
