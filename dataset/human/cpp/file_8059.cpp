#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> sum(N);
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    if (i > 0) sum[i] = sum[i-1] + x;
    else sum[i] = x;
  }
  
  ll m = abs(2*sum[0]-sum[N-1]);
  for (int i = 1; i < N-1; i++) {
    m = min(m,abs(2*sum[i]-sum[N-1]));
  }
  
  cout << m << endl;
}
