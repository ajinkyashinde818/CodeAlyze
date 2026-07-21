#include <bits/stdc++.h>
using namespace std;

long long r, g, b, n;

long long solve();

int main() {
  cin >> r >> g >> b >> n;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0;
  for(long long i = 0; i <= n; ++i)
    for(long long j = 0; j <= n; ++j) {
      long long now = n - i * r - j * g;
      if(now >= 0 && now % b == 0) ++ans;
    }
  return ans;
}
