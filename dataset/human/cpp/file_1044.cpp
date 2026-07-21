#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int i=0; i<N/R+1; i++) {
    for (int j=0; j<N/G+1; j++) {
      if ((N-i*R-j*G) < 0) {
        break;
      }
      if ((N-i*R-j*G) % B == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
