#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (long long i = 0; i < n; i++)
  {
    cin >> a.at(i);
    sum += a.at(i);
  }

  long long x = a.at(0);
  long long y = sum - a.at(0);
  long long ans = abs(x - y);
  for (long long i = 1; i < n - 1; i++)
  {
    x += a.at(i);
    y -= a.at(i);
    ans = min(ans, abs(x - y));
  }

  cout << ans << endl;
}
