#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int R, G, B, N, r, g, b, rg, ans = 0;
  cin >> R >> G >> B >> N;
  
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      r = i, g = j, rg = r*R+g*G, b = (N - rg)/B;
      if (b >= 0 && b <= 3000 && (N - rg)%B == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
