#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;
int mul(int a, int b) {
  return (long long) a * b % mod;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> color;
  for (auto c : s) {
    color.push_back(c == 'B');
  }

  int res = 1, choices = 0;
  for (auto c : color) {
    c ^= (choices & 1);
    if (c == 0) { // white
      if (choices == 0) {
        res = 0;
        break;
      }
      else {
        res = mul(res, choices);
        choices--;
      }
    }
    if (c == 1) { // black
      choices++;
    }
  }

  int ans = (choices == 0) ? res : 0;
  for (int i = 1; i <= n; i++) {
    ans = mul(ans, i);
  }
  cout << ans << '\n';
  return 0;
}
