#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      int tmp = R*i + G*j;
      if (tmp <= N) {
        if ((N - tmp) % B == 0) ans++;
      }
      else continue;
    }
  }
  cout << ans << endl;
}
