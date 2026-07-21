#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int N; cin >> N;
  vector<ll> cumsum(N+1, 0);
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    cumsum[i+1] = cumsum[i]+a;
  }

  ll ans = 1e18;
  for (int i = 1; i < N; ++i) {
    ans = min(ans, abs(cumsum[N]-2*cumsum[i]));
  }

  cout << ans << endl;
}
