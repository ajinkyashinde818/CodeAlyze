#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  ll n, asum = 0, bsum = 0;
  cin >> n;
  vector<ll> a;
  for (ll i = 0; i < n; i++) {
    ll m;
    cin >> m;
    a.push_back(m);
    asum += m;
  }
  ll res = 1e10;
  for (ll i = 0; i < n-1; i++) {
    bsum += a[i];
    asum -= a[i];
    ll c = abs(asum-bsum);
    res = res > c ? c : res;
  }
  cout << res << "\n";
  return 0;
}
