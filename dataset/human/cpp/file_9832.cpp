#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll const MOD = 1e9 + 7;

int main() {
  ll N;
  string S;
  cin >> N >> S;
  map<char, ll> m;
  for (int i = 0; i < N; i++) {
    if (m.find(S[i]) == m.end()) {
      m[S[i]] = 1;
    } else {
      m[S[i]]++;
    }
  }
  ll ans = 1;
  for (auto p : m) {
    ll cnt = p.second;
    ans = (ans * (cnt + 1) % MOD) % MOD;
  }
  cout << (ans - 1) % MOD << endl;
  return 0;
}
