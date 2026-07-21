#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a.at(i);

  vector<long long> s(N + 1, 0);
  for (int i = 0; i < N; ++i) s.at(i + 1) = s.at(i) + a.at(i);

  long long res = 1LL << 60;
  for (int i = 1; i < N; i++) {
    res = min(res, abs(s.at(N) - s.at(i) * 2));
  }

  cout << res << endl;
}
