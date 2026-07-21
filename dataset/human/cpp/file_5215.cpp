#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, r;
  cin >> n >> r;

  if (n >= 10) cout << r << '\n';
  else cout << r + (1000 - 100 * n) << '\n';

  return (0);
}
