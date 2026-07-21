#include <bits/stdc++.h>
using namespace std;

int n, sum = 0, scnt = 0;
vector<int> memo[100005];

void solve();

int main() {
  cin >> n;
  while(sum < n) sum += ++scnt;
  if(sum != n)
    cout << "No" << endl;
  else
    solve();
  return 0;
}

void solve() {
  int nlast = 2, now = 1, cnt = 0;
  cout << "Yes" << endl;
  while(1) {
    while(now < nlast) {
      memo[now].push_back(cnt + 1);
      memo[nlast].push_back(cnt + 1);
      ++now;
      ++cnt;
    }
    ++nlast;
    now = 1;
    if(cnt == n) break;
  }
  cout << scnt + 1 << endl;
  for(int i = 1; i <= scnt + 1; ++i) {
    cout << memo[i].size();
    for(int j = 0; j < memo[i].size(); ++j)
      cout << " " << memo[i][j];
    cout << endl;
  }
}
