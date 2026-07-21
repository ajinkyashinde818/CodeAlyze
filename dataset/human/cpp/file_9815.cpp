#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<long long> alphabet(26);
  for (int i = 0; i < S.size(); i++) alphabet[S[i] - 'a']++;
  const int MOD = 1e9 + 7;
  long long ans = 1;
  for (int i = 0; i < 26; i++) ans = (ans * (alphabet[i] + 1)) % MOD;
  ans--;
  cout << ans << endl;
}
