#include <bits/stdc++.h>
using namespace std;

int main() {
  int MOD = 1000000007;
  int N; cin >> N;
  string S; cin >> S;
  vector<long long> cnt(26, 0);
  for (int i = 0; i < N; i++) cnt.at(S.at(i) - 'a')++;
  long long ans = 1;
  for (long long c : cnt) {
    if (c == 0) continue;
    ans = (ans * (c + 1)) % MOD;
  }
  cout << ans - 1 << endl;
}
