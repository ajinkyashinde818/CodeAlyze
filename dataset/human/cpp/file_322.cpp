#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int rmax = N / R;
  int gmax = N / G;
  int ans = 0;

  for (int i=0; i<=rmax; i++) {
    for (int j=0; j<=gmax; j++) {
      int zan = N - (i*R) - (j*G);
      if (zan >= 0 && zan % B == 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
