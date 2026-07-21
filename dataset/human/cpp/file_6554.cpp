#include <bits/stdc++.h>

using namespace std;

constexpr int64_t mod_factor = 1'000'000'007LL;

int solve(const string& S) {
  if (S.front() != 'B' || S.back() != 'B')
    return 0;

  int64_t result = 1;
  bool is_left = true;
  int l_cnt = 1;
  int half = S.size() / 2;
  for (size_t i = 1; i < S.size(); ++i) {
    if (S[i] == S[i - 1]) {
      is_left = !is_left;
    }
    if (is_left) {
      ++l_cnt;
      if (l_cnt > half) {
        return 0;
      }
    } else {
      if (l_cnt <= 0) {
        return 0;
      }
      result = (result * l_cnt) % mod_factor;
      l_cnt -= 1;
    }
  }
  if (l_cnt != 0) {
    return 0;
  }
  for (int i = half; i > 1; --i) {
    result = (result * i) % mod_factor;
  }
  return result;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  auto ans = solve(S);
  cout << ans << endl;
}
