#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll abs_sum = 0;
  ll abs_min = 1e9;
  int negative_num = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (a < 0) negative_num++;
    abs_min = min(abs(a), abs_min);
    abs_sum += abs(a);
  }

  if (negative_num % 2 == 1) abs_sum -= abs_min * 2LL;

  cout << abs_sum << endl;

  return 0;
}
