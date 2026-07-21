#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

const int MOD = 1000000007;

ll factorial(ll n) {
  if(n == 1) return 1;
  return (n * factorial(n - 1)) % MOD;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  string s;
  cin >> s;
  const char *sptr = s.c_str();
  int invrl[n * 2];
  for(int i = 0; i < 2 * n; i++) {
    int invnum = i;
    if(sptr[i] == 'W') invnum++;
    invrl[i] = invnum % 2;
  }
  //for(int i = 0; i < 2 * n; i++) {
  //  cout << invrl[i] << " ";
  //}
  //cout << "\n";
  ll lsum = 0;
  ll ans = 1;
  for(int lptr = 0; lptr < 2 * n; lptr++) {
    if(invrl[lptr] == 0) lsum++;
    else {
      if (lsum <= 0) {
        lsum = -1;
        break;
      }
      ans = (ans * lsum) % MOD;
      lsum--;
    }
  }

  if(lsum != 0) {
    cout  << 0 << "\n";
    return 0;
  }
  ans = (ans * factorial(n)) % MOD;
  cout << ans << "\n";

  return 0;
}
