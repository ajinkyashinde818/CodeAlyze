// Last Change: 10/24/2019 19:53:03.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> ipt(m);
  for (auto &&e : ipt) {
    cin >> e;
  }
  vector<ll> val(n, 0);
  for (int i = m - 1; i >= 0; --i) {
    if (val[ipt[i] - 1] == 0) {
      val[ipt[i] - 1] = 1;
      cout << ipt[i] << endl;
    }
  }
  for (ll i = 0; i < n; ++i) {
    if (val[i] == 0) {
      cout << i + 1 << endl;
    }
  }
}
