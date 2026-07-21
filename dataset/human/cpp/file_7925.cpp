#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int N; cin >> N;
  vector<ll> a(N),b(N),c(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  
  b[0] = a[0];
  for (int i = 1; i < N; i++) b[i] = b[i-1] + a[i];
  for (int i = 0; i < N; i++) c[i] = b[N-1] - b[i];
  
  ll ans = 1e18;
  for (int i = 0; i < N-1; i++) ans = min(ans,abs(b[i]-c[i]));
  
  
  cout << ans << endl;
}
