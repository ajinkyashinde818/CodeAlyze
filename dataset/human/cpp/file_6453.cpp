#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>
#include <iostream>

using namespace std;

constexpr int mod = 1'000'000'007;

char dat[1048576];

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  scanf("%s", dat);
  vector<int> dir(2*n); // 0: opening, 1: closing
  char last = 'W';
  int par = 0;
  for (int i = 0; i < 2*n; i++) {
    if (dat[i] == last) {
      if (par == 0) {
        dir[i] = 1;
      } else {
        dir[i] = 0;
      }
    } else {
      if (par == 0) {
        dir[i] = 0;
      } else {
        dir[i] = 1;
      }
    }
    par = dir[i];
    last = dat[i];
  }
  int m = 2 * n;
  {
    int depth = 0;
    long long ans = 1;
    for (int i = 0; i < m; i++) {
      if (dir[i] == 0) {
        depth++;
      } else {
        ans *= depth;
        ans %= mod;
        depth--;
      }
      if (depth < 0) {
        printf("0\n");
        return 0;
      }
    }
    if (depth != 0) {
      printf("0\n");
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      ans *= i;
      ans %= mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
