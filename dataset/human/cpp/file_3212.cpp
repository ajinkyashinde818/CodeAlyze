#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> list(n);
  int cnt = 0;
  ll minv = LLONG_MAX;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> list[i];
    if (list[i] < 0) {
      cnt++;
      list[i] *= -1;
    }
    minv = min(minv, list[i]);
    sum += list[i];
  }
  if (cnt % 2) {
    sum -= minv * 2;
  }
  cout << sum << endl;
  return 0;
}
