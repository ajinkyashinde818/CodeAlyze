#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long X=0, x=0,ans=10000000000000LL;
  cin >> n;
  
  vector<long long> a(n);
  for(int i=0; i<n; i++){
    cin >> a.at(i);
    X += a.at(i);
  }
  
  for(int i=0; i<n; i++){
    x+=a.at(i);
    if(i+1 < n)
      ans = min(ans, abs(X-2*x));
  }
  cout << ans << endl;
}
