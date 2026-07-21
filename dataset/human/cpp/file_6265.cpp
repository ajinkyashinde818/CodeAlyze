#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int dp[201][101];

int rec(int w, int b) {
  if(~dp[w][b]) return dp[w][b];
  set< int > grundy;
  if(w > 0) grundy.emplace(rec(w - 1, b));
  for(int i = 1; i <= w; i++) {
    if(b - i >= 0) grundy.emplace(rec(w, b - i));
  }
  if(b > 0) grundy.emplace(rec(w + 1, b - 1));
  int beet = 0;
  while(grundy.count(beet)) ++beet;
  return dp[w][b] = beet;
}

int main() {
  int N;
  memset(dp, -1, sizeof(dp));
  cin >> N;
  int uku = 0;
  while(N--) {
    int w, b;
    cin >> w >> b;
    uku ^= rec(w, b);
  }
  cout << (uku == 0) << endl;
}
