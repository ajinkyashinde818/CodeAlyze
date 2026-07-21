#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  vector<string> b(m);

  rep (i, n) {
    cin >> a[i];
  }

  rep (i, m) {
    cin >> b[i];
  }

  bool res = false;
  rep (i, n-m) rep (j, n-m) {
    bool isOk = true;
    rep (k, m) {
      rep (l, m) {
        if (b[k][l] != a[i+k][j+l]) isOk = false;
      }
    }
    if (isOk) res = true;
  }

  if (m == n) {
    bool isOk = true;
    rep (i, m) rep (j, n) {
      if (b[i][j] != a[i][j]) isOk = false;
    }
    if (isOk) res = true;
  }

  cout << (res ? "Yes" : "No") << endl;
}
