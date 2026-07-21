#include <bits/stdc++.h>

using namespace std;

const uint64_t MOD = 1e+9 + 7;

uint64_t fact(uint64_t n)
{
  uint64_t prd = 1;
  for (uint64_t i = 2; i <= n; ++i) {
    prd = (prd * i) % MOD;
  }
  return prd;
}

int main()
{
  uint64_t N;
  cin >> N;
  
  string S;
  cin >> S;
  
  uint64_t cntL = 1, cntR = 0;
  vector<char> dir(2 * N, ' ');
  dir[0] = 'L';
  for (uint64_t n = 1; n < 2 * N; ++n) {
    if (S[n - 1] == S[n]) {
      dir[n] = (dir[n - 1] == 'L') ? 'R' : 'L';
    } else {
      dir[n] = dir[n - 1];
    }
    
    if (dir[n] == 'L') { ++cntL; } else { ++cntR; }
  }
  
  if ((dir[2 * N - 1] != 'R') || (cntL != cntR) || (S[0] == 'W' || (S[2 * N - 1] == 'W'))) {
    cout << 0 << endl;
    return 0;
  }
  
  vector<uint64_t> csL(2 * N + 1, 0), csR(2 * N + 1, 0);
  for (uint64_t n = 0; n < 2 * N; ++n) {
    csL[n + 1] = csL[n];
    csR[n + 1] = csR[n];
    if (dir[n] == 'L') {
      ++csL[n + 1];
    } else {
      ++csR[n + 1];
    }
  }
  
  uint64_t prd = 1;
  for (uint64_t n = 0; n < 2 * N; ++n) {
    if (dir[n] == 'R') {
      prd = (prd * (csL[n] - csR[n])) % MOD;
    }
  }
  
  uint64_t ans = (prd * fact(N)) % MOD;
  cout << ans << endl;
  
  return 0;
}
