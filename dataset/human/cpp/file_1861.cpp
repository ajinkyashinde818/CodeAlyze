#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cfloat>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(void){
  cout << std::fixed << std::setprecision(16);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  std::vector<int> a(m);
  for (auto &e: a) cin >> e;

  std::vector<bool> used(n+1, false);

  for (int i = m-1; i >= 0; i--) {
    if (!used[a[i]]) {
      cout << a[i] << endl;
      used[a[i]] = true;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      cout << i << endl;
    }
  }


  return 0;
}
