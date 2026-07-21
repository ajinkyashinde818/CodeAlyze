#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  char C;
  map<char, long> MA;
  while (cin >> C) MA[C]++;
  long ans = 1;
  for (auto ma : MA) (ans *= (ma.second + 1)) %= 1000000007;
  cout << ans - 1 << "\n";
}
