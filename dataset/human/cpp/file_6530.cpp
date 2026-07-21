#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int R[200000];
int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < 2 * n; ++i) {
    char c = i % 2 == 0 ? 'B' : 'W';
    R[i] = s[i] != c;
  }
  
  long sum = 1;
  int cnt = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (R[i]) {
      sum = sum * cnt % mod;
      --cnt;
    } else {
      ++cnt;
    }
  }
  if (cnt != 0) sum = 0;
  
  for (int i = 1; i <= n; ++i) {
    sum = sum * i % mod;
  }
  cout << sum << endl;
  
}
