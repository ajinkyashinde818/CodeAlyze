#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  long long ans = 0;
  int cnt = 0;
  long long mn = 2000000000;
  for(int i = 0; i < n; ++i){
    long long k;
    cin >> k;
    if(k < 0) cnt++;
    k = abs(k);
    mn = min(mn, k);
    ans += k;
  }
  
  if(cnt % 2) ans -= mn * 2;
  cout << ans << endl;
}
