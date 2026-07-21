#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  ll x = 0, y = 0, min = 1000000000000000;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x += a[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    x -= a[i];
    y += a[i];
    if (abs(x - y) < min) min = abs(x - y);
  }
  cout << min << endl;
}
