#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;
using ull = uint_fast64_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;
#define rep(i, n) for (ull i = 0; i < n; ++i)
#define rep1(i, n) for (ull i = 1; i < n; ++i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++it)
#define pb push_back
#define fi first
#define se second
#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }
template <typename T> void vecout(const T &v) {
  for (auto it = v.begin(); it != v.end();
       ++it, cout << (it != v.end() ? " " : "\n")) {
    cout << *it;
  }
}
template <typename T> void arrout(const T arr, ull n) {
  for (ull i = 0; i < n; ++i, cout << (i != n ? " " : "\n")) {
    cout << arr[i];
  }
}

void solve() {
  // main coding
  ll n; cin>>n;
  vll A(n);
  rep(i,n) cin>>A[i];
  vector<vll> dp(n);
  rep(i,n) dp[i].resize(2);
  // dp[i][j] j=0ならA[i]をFlipしてない、j=1ならFlipした時の最大
  dp[0][0]=A[0]; dp[0][1]=-A[0];
  rep1(i,n) {
    dp[i][0]=max(dp[i-1][0]+A[i],dp[i-1][1]-A[i]);
    dp[i][1]=max(dp[i-1][0]-A[i],dp[i-1][1]+A[i]);
  }
  cout<<dp[n-1][0]<<endl;
}

int main() {
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
