#include <bits/stdc++.h>
using namespace std;

int main(){
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  
  long long ans = 0;
  for(int i = 0; i*r <= n; i++){
    for(int j = 0; j*g <= n; j++){
      int now = n - i*r - j*g;
      if(now < 0) continue;
      if(now % b) continue;
      ans++;
    }
  }
  
  cout << ans << endl;
}
