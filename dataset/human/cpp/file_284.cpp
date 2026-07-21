#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

int main() {
  int r,g,b,n;
  cin >> r >> g >> b >> n;

  int rmax = n / r;
  // cout << rmax << endl;
  ll ans = 0;
  for (int i = 0; i <= rmax; ++i) {
    int rem = n - i * r;
    int gmax = (rem / g) + 1;
    for (int j = 0; j <= gmax; ++j) {
      int remain = rem - j * g;
      if (remain >= 0 and remain % b == 0) ans += 1;
    }
  }
  cout << ans << endl;
}
