#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3010;

int meth[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int r, g, b, n;
  scanf("%d%d%d%d", &r, &g, &b, &n);
  for (int i = 0; i <= n; i += r)
    meth[i] = 1;
  for (int i = g; i <= n; ++i) {
    meth[i] += meth[i - g];
  }for (int i = b; i <= n; ++i) {
    meth[i] += meth[i - b];
  }
  printf("%d\n", meth[n]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
