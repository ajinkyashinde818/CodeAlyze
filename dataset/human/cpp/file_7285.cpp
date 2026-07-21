#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  vector<long long> S(N);
  S.at(0) = a.at(0);
  for (int i = 1; i < N; i++) S.at(i) += S.at(i-1) + a.at(i);
  long long ans = 1LL << 60;
  for (int i = 0; i < N-1; i++) ans = min(ans, abs(2*S.at(i)-S.at(N-1)));
  cout << ans << endl;
}
