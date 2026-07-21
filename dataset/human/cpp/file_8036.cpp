#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N; scanf("%d", &N);
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }
  for (int i = 1; i < N; ++i) {
    A[i] += A[i - 1];
  }
  ll ans = LLINF;
  for (int i = 0; i < N - 1; ++i) {
    ans = min(ans, abs(A[i] - (A[N - 1] - A[i])));
  }
  printf("%lld\n", ans);
  return 0;
}
