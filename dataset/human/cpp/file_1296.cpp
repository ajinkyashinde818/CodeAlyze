#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i*r <= n; i++) {
    for (int j = 0; i*r+j*g <= n; j++) {
      int rem = n-i*r-j*g;
      if (!(rem%b))
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
