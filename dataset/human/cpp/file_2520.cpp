#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  ll N; cin >> N;
  vector<ll> A(N);
  ll c = 0;
  ll a = 0;
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) < 0) {
      A.at(i) *= -1;
      c++;
    }
    a += A.at(i);
  }

  if (c%2 == 1) {
    sort(A.begin(), A.end());
    a -= A.front()*2;
  }
  cout << a << endl;

  return 0;
}
