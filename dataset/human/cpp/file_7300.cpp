#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define FOR(i, first, last) for (int i = (first); i < (last); ++i)
#define REP(i, n) FOR(i, 0, n)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) std::cerr << #x << " = " << (x) << std::endl;

inline int to_int(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string to_string(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

typedef unsigned long long ull;
typedef unsigned long ul;

int main() {
  int N;
  cin >> N;
  vector<long long> v(N);
  vector<long long> s(N);
  REP(i, N) cin >> v[i];

  s[0] = v[0];
  for (int i = 1; i < N; i++)
    s[i] = s[i - 1] + v[i];

  long long S = accumulate(v.begin(), v.end(), 0ll);
  long long ans = LLONG_MAX;
  for (int i = 0; i < N - 1; i++) {
    long long x = s[i];
    long long y = S - x;
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;

  return 0;
}
