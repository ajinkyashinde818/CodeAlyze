#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, Y) for (int(X) = 0; (X) <= (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(long long R, long long G, long long B, long long N) {
  ll ans = 0;
  rep(r, 3000) {
    ll rest = N - R * r;
    if (rest < 0) {
      break;
    }
    rep(g, 3000) {
      ll rest2 = rest - G * g;
      if (rest2 < 0) {
        break;
      }
      if (rest2 >= 0 && rest2 % B == 0) {
        ans++;
      }
    }
  }
  print(ans);
}

int main() {
  long long R;
  scanf("%lld", &R);
  long long G;
  scanf("%lld", &G);
  long long B;
  scanf("%lld", &B);
  long long N;
  scanf("%lld", &N);
  solve(R, G, B, N);
  return 0;
}
