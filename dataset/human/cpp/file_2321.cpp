#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef long long int ll;
typedef vector<ll> V;
typedef vector<V> VV;

int main() {
  // Happy hacking!
  ll n;
  V a;

  ll sum = 0;
  ll n_neg = 0;
  ll min_abs = 1000000000;

  ll res;

  cin >> n;

  for(ll i=0; i<n; i++) {
    ll t;
    cin >> t;
    a.push_back(t);
  }

  for(ll i=0; i<n; i++) {
    if(a[i] < 0) {
      sum -= a[i];
      n_neg++;
    } else {
      sum += a[i];
    }

    if(min_abs > abs(a[i])) {
      min_abs = abs(a[i]);
    }
  }

  if(n_neg % 2) {
    res = sum - min_abs * 2;
  } else {
    res = sum;
  }

  cout << res << endl;

  return 0;
}
