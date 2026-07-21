#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  long long x = 0, y = 0, ans = LLONG_MAX;
  cin >> n;
  vector<long long> a(n);

  for (int i = 0; i < n; ++i){
    cin >> a[i];
    x += a[i];
  }
  for (int i = 0; i < n; ++i){
    y += a[i];
    if (i + 1 < n) ans = min(ans, abs(x - 2*y));
  }
  cout << ans << endl;

  return 0;
}
