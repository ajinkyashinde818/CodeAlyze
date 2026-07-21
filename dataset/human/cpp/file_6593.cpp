#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

char color[2] = {'B', 'W'};
int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 1;
  int rem = 0;
  for (int i = 0; i < 2*n; ++i) {
    char c = s[i];
    char tobe = color[rem&1];
    if (tobe == c) {
      if (rem >= 2*n-i) { cout << 0 << endl; return 0; }
      ++rem;
    }
    else {
      if (rem == 0) { cout << 0 << endl; return 0; }
      ans *= rem;
      ans %= MOD;
      --rem;
    }
  }

  for (int i = 1; i <= n; ++i) {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
}
