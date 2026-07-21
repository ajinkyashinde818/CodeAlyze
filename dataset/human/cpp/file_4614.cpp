#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve(ll N, ll R) {
  cout << R + (N<10 ? 1000 - 100*N : 0) << endl;
}

int main() {
  ll N;
  cin >> N;
  ll R;
  cin >> R;
  solve(N, R);
  return 0;
}
