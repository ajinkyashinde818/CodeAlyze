#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <numeric>
#include <ios> // std::left, std::right

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
  ll n, m = 1000000000;
  cin >> n;
  vector<ll> a(n, 0);
  int b = 1;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] < 0)
    {
      b *= (-1);
      a[i] *= (-1);
    }
    m = min(m, a[i]);
  }

  if (b == 1)
  {
    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
  }
  else
  {
    cout << accumulate(a.begin(), a.end(), 0LL) - 2 * m << endl;
  }

  return 0;
}
