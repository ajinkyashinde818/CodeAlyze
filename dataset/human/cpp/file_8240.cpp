#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e16;

template <class T> inline bool chmin(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<ll> as(N + 1, 0);
  int a;
  for(int i = 1; i <= N; ++i) {
    cin >> a;
    as[i] = as[i - 1] + a;
  }
  ll ans = INF;
  for(int i = 1; i < N; ++i) {
    auto x = as[i];
    auto y = as[N] - as[i];
    chmin(ans, abs(x - y));
  }
  cout << ans << endl;
  return 0;
}
