#include <iostream>
#include <vector>

using namespace std;

int main(){
  int r, g, b, n;
  cin >> r >> g >> b >> n;

  int ans = 0;
  for(int rr=0; rr<=n; rr++){
    for(int gg=0; gg<=n; gg++){
      int bb = (n - rr*r - gg*g) / b;
      int out_b = (n - rr*r - gg*g) % b;
      if( rr*r + gg*g + bb*b == n && out_b == 0 && bb >= 0 ) ans += 1;
    }
  }

  cout << ans;
}
