#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll cnt = 0, ans = 0, mina = llabs(a[0]);
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      cnt++;
    }
    ans += llabs(a[i]);
    if (llabs(a[i]) < mina) {
      mina = llabs(a[i]);
    }
  }
  if (cnt%2 == 1) {
    ans -= 2*mina;
  }
  cout << ans << endl;
  return 0;
}
