#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int div_R = N / R;
  int div_G = N / G;
  int ans = 0;
 
  for (int r = 0; r <= div_R; r++) {
    for (int g = 0; g <= div_G; g++) {
      int left = (N - (R * r + G * g));
      if (left % B == 0 && left / B >= 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
