#include <iostream>
#include <iomanip>
#include <queue>
#include <deque>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <bitset>

#define REP(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define FILL(x, y) memset(x, y, sizeof(x))
#define pb push_back
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

template<class T>bool chmax(T &a, const T &b) {
   if (a < b) {
      a = b;
      return 1;
   }
   return 0;
}
template<class T>bool chmin(T &a, const T &b) {
   if (a > b) {
      a = b;
      return 1;
   }
   return 0;
}

using namespace std;
using ll = long long;

const int kInf = 2e9;
const ll kLInf = 2e18;

int gcd (int a, int b) {
   return b ? gcd(b, a % b) : a;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, R;
int main()
{
   cout << fixed << setprecision(10);
   cin >> N >> R;
   int ans;
   if (N >= 10) {
      ans = R;
   } else {
      ans = R + 100 * (10 - N);
   } 
   cout << ans << endl;
   return 0;
}
