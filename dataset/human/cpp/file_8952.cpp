#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<string> a(n); REP(i, n) cin >> a[i];
  vector<string> b(m); REP(i, m) cin >> b[i];

  REP(i, n-m+1) {
    int index = -1;
    while (true) {
      bool ok = true;
      index = a[i].find(b[0], index + 1);
      if (index != -1 && index <= n-m) {
        FOR(j, 1, m) {
          int ind = a[i+j].find(b[j], index);
          if (ind == index) continue;
          ok = false;
        }
      } else break;
      if (ok) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
