#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  ll A;
  int n = 0;
  int m = 0;
  ll d = 1LL << 60;
  ll ans = 0;
  for (int i=0; i<N; i++) {
    cin >> A;
    if (A > 0) {
      ans += A;
      d = min(d, A);
    } else if (A == 0) {
      m++;
    } else {
      n++;
      A = -A;
      ans += A;
      d = min(d, A);
    }
  }
  if (m > 0 || n % 2 == 0) cout << ans;
  else cout << ans - 2*d << endl;
}
