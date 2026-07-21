#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n, a;
  cin >> n;
  vector<long long> sum(n, 0);
  cin >> a; sum[0] = a;
  for (int i = 1; i < n; ++i) {
    cin >> a;
    sum[i] = sum[i-1] + a;
  }
  long long res = 1e18;
  for (long long i = 0; i < n-1; ++i) {
    long long tmp = abs(sum[n-1]-2*sum[i]);
    if (tmp < res) res = tmp;
  }
  cout << res << endl;


  return 0;
}
