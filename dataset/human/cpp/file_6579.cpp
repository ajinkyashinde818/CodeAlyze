#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int base = 1e9 + 7;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  
  vector<int> dif(2*n+1, 0);
  dif[0] = (s[0] == 'B' ? 1 : 0);
  dif[2*n] = (s[2*n-1] == 'B' ? 1 : 0);
  for (int i = 1; i < 2*n; ++i)
    if (s[i] != s[i-1]) dif[i] = 1;
  
  ll total = 1;
  int cur = 0, cnt = 0;
  for (int d: dif) {
    if (cur == 0) {
      if (d == 1) ++cnt;
      else cur = 1;
    }
    else {
      total = total * cnt % base;
      if (d == 1) --cnt;
      else cur = 0;
    }
  }
  
  if (cnt == 0) while (n) total = total * n-- % base;
  else total = 0;
  cout << total << endl;
}
