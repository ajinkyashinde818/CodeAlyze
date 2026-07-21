#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  int n, r;
  cin >> n >> r;
  if (n >= 10) {
    cout << r << endl;
  } else {
    cout << r + 100 * (10 - n) << endl;
  }
}
