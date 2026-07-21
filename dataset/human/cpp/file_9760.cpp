#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  vector<int> alpha(26, 0);
  for(int i = 0; i < S.size(); ++i) {
    for(int j = 0; j < 26; ++j) {
      if(S[i] == 'a'+j) alpha[j]++;
    }
  }
  long long ans=1;
  for(int i = 0; i < 26; ++i) {
    if(alpha[i] == 0) continue;
    ans *= (alpha[i]+1);
    ans %= 1000000007;
  }
  cout << ans-1 << endl;

  return 0;
}
