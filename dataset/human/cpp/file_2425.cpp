#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
  int n;
  cin >> n;
  bool zero = false;
  ll ret = 0;
  ll minAbs = 2e9;
  int neg = 0;
  while(n--) {
    ll t;
    cin >> t;
    if(t < 0) neg++;
    else if(t == 0) zero = true;
    ret += abs(t);
    minAbs = min(minAbs, abs(t));
  }
  if(!zero && neg%2) ret -= 2*minAbs;
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}
