#include "bits/stdc++.h"

// clang-format off
template <typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template <typename T> T clamp(T val, T min, T max) { return val < min ? min : (max < val ? max : val); }
char capitalize(char c) { return static_cast<char>(std::toupper(static_cast<unsigned char>(c))); }
// template <typename T> size_t max_index(T begin, T end) { return distance(begin, max_element(begin, end)); }
// template <typename T> size_t min_index(T begin, T end) { return distance(begin, min_element(begin, end)); }
// clang-format on

#define int long long
#define YES "YES"
#define NO  "NO"
#define MOD 1000000000+7
#define forit(v) for(auto it = v.begin(); it != v.end(); ++it)

using namespace std;

int R;
int G;
int B;
int N;

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int num = 0;
  // num = numeric_limits<int>::max();
  // num = numeric_limits<int>::min();
  bool flag = false;
  // flag = true;

  cin >> R >> G >> B >> N;

  for (int r = 0; ; ++r) {
    if (r * R == N) ++num;
    if (r * R >= N) break;
    for (int g = 0; ; ++g) {
      int tmp = r * R + g * G;
      if (tmp == N) ++num;
      if (tmp >= N) break;

      // B
      int tmpB = N - tmp;
      if (tmpB % B == 0) ++num;
    }
  }

  cout << num << endl;
  // cout << (flag ? YES : NO) << endl;
  
  return 0;
}
