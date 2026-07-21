#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  long long cnt = 0;
  for (int r = 0; r <= N/R; r++) {
    for (int g = 0; g <= N/G; g++) {
      int tmp = N - R*r - G*g;
      if (tmp % B == 0 && tmp / B >= 0) cnt++;
    }
  }
  cout << cnt << endl;
}
