#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 105000;

int n;
int a[MAXN];
long long dp[MAXN];
long long sum[MAXN];
long long mx = 0;

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  } 

  for (int i = n - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + a[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    dp[i] = a[i] + dp[i + 1];
    if (i == n - 1) {
      mx = -2 * a[i];
    } else {
      dp[i] = max(dp[i], -a[i] + sum[i + 1] + mx);
      mx = max(mx, dp[i + 1] - sum[i + 1] - 2 * a[i]);
    }
    // cerr << dp[i] << endl;
  }

  cout << dp[0] << endl;

  return 0;
}
