#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main()	{
  ll n;
  cin >> n;
  ll a[n] = {0};
  ll sum = 0;
  for (ll i = 0; i < n; i++)	{
    cin >> a[i];
    sum += a[i];
  }
  ll asum = 0;
  ll mindif = 1000000000000000;
  for (ll i = n - 1; i >= 1; i--)	{
    sum -= a[i];
    asum += a[i];
    mindif = min(mindif, abs(sum - asum));
  }
  cout << mindif << endl;
  return 0;
}
